/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file LICENSE.rst or https://cmake.org/licensing for details.  */
#include "cmExportBuildPackageInfoGenerator.h"

#include <cassert>
#include <map>
#include <utility>
#include <vector>

#include <cmext/string_view>

#include <cm3p/json/value.h>

#include "cmAlgorithms.h"
#include "cmGeneratorExpression.h"
#include "cmList.h"
#include "cmPackageInfoArguments.h"
#include "cmStateTypes.h"
#include "cmStringAlgorithms.h"

cmExportBuildPackageInfoGenerator::cmExportBuildPackageInfoGenerator(
  cmPackageInfoArguments arguments)
  : cmExportPackageInfoGenerator(std::move(arguments))
{
  this->SetNamespace(cmStrCat(this->GetPackageName(), "::"_s));
}

bool cmExportBuildPackageInfoGenerator::GenerateMainFile(std::ostream& os)
{
  if (!this->CollectExports([&](cmGeneratorTarget const*) {})) {
    return false;
  }

  if (!this->CheckDefaultTargets()) {
    return false;
  }

  Json::Value root = this->GeneratePackageInfo();
  root["cps_path"] = "@prefix@";

  Json::Value& components = root["components"];

  // Create all the imported targets.
  for (auto const& exp : this->Exports) {
    cmGeneratorTarget* const target = exp.Target;
    cmStateEnums::TargetType targetType = this->GetExportTargetType(target);

    Json::Value* const component =
      this->GenerateImportTarget(components, target, targetType);
    if (!component) {
      return false;
    }

    ImportPropertyMap properties;
    if (!this->PopulateInterfaceProperties(target, properties)) {
      return false;
    }
    this->PopulateInterfaceLinkLibrariesProperty(
      target, cmGeneratorExpression::InstallInterface, properties);

    if (targetType != cmStateEnums::INTERFACE_LIBRARY) {
      auto configurations = Json::Value{ Json::objectValue };

      // Add per-configuration properties.
      for (std::string const& c : this->Configurations) {
        this->GenerateInterfacePropertiesConfig(configurations, target, c);
      }

      if (!configurations.empty()) {
        (*component)["configurations"] = configurations;
      }
    }

    // De-duplicate include directories prior to generation.
    auto it = properties.find("INTERFACE_INCLUDE_DIRECTORIES");
    if (it != properties.end()) {
      auto list = cmList{ it->second };
      list = cmList{ list.begin(), cmRemoveDuplicates(list) };
      properties["INTERFACE_INCLUDE_DIRECTORIES"] = list.to_string();
    }

    // Set configuration-agnostic properties for component.
    this->GenerateInterfaceProperties(*component, target, properties);
  }

  this->GeneratePackageRequires(root);

  // Write the primary packing information file.
  this->WritePackageInfo(root, os);

  bool result = true;

  return result;
}

void cmExportBuildPackageInfoGenerator::GenerateInterfacePropertiesConfig(
  Json::Value& configurations, cmGeneratorTarget* target,
  std::string const& config)
{
  std::string const& suffix = PropertyConfigSuffix(config);

  ImportPropertyMap properties;

  assert(this->GetExportTargetType(target) != cmStateEnums::INTERFACE_LIBRARY);
  this->SetImportLocationProperty(config, suffix, target, properties);
  if (properties.empty()) {
    return;
  }

  this->SetImportDetailProperties(config, suffix, target, properties);

  // TODO: PUBLIC_HEADER_LOCATION

  Json::Value component =
    this->GenerateInterfaceConfigProperties(suffix, properties);
  if (!component.empty()) {
    configurations[config.empty() ? std::string{ "noconfig" } : config] =
      std::move(component);
  }
}

std::string cmExportBuildPackageInfoGenerator::GetCxxModulesDirectory() const
{
  // TODO: Implement a not-CMake-specific mechanism for providing module
  // information.
  return {};
}
