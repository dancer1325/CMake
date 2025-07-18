* goal
  * how to use CMake | project
* `cmake-buildsystem(7)`
  * how to
    * maintain a buildsystem
    * become familiar -- with the -- build targets / can be represented | CMake
* `cmake-packages(7)`
  * how to create packages / can be consumed -- by -- third-party CMake-based buildsystems

Introduction
============

The CMake tutorial provides a step-by-step guide that covers common build
system issues that CMake helps address. Seeing how various topics all
work together in an example project can be very helpful.

Steps
=====

The tutorial documentation and source code examples can be found in
the ``Help/guide/tutorial`` directory of the CMake source code tree.
Each step has its own subdirectory containing code that may be used as a
starting point. The tutorial examples are progressive so that each step
provides the complete solution for the previous step.

.. toctree::
  :maxdepth: 2

  A Basic Starting Point
  Adding a Library
  Adding Usage Requirements for a Library
  Adding Generator Expressions
  Installing and Testing
  Adding Support for a Testing Dashboard
  Adding System Introspection
  Adding a Custom Command and Generated File
  Packaging an Installer
  Selecting Static or Shared Libraries
  Adding Export Configuration
  Packaging Debug and Release

..
  Whenever a step above is renamed or removed, leave forwarding text in
  its original document file, and list it below to preserve old links
  to cmake.org/cmake/help/latest/ URLs.

.. toctree::
  :maxdepth: 1
  :hidden:
