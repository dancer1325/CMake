Step 1: A Basic Starting Point
==============================

* MOST basic CMake project
  * == 👀executable built -- from -- 1! source code file👀
  * requirements
    * ``CMakeLists.txt`` / 3 commands

* CMake
  * supports
    * upper, lower & mixed case commands
      * recommended
        * lower case

* `cmake_minimum_required`
  * command /
    * | any project's top MOST CMakeLists.txt
    * 👀establishes 
      * policy settings
      * CMake's version👀

* `project`
  * command /
    * start a project
    * allows, set
      * the project name
      * language
      * version number
  * required | every project
  * recommendations
    * place AFTER `cmake_minimum_required`

* `add_executable`
  * command /
    * tells CMake -- , via specified source code files, to -- create an executable 

Goal
----

* CMake's basic
  * syntax,
  * commands,
  * variables
* build a basic CMake Project

Helpful Resources
-----------------

* :command:`add_executable`
* :command:`cmake_minimum_required`
* :command:`project`

Files to Edit
-------------

* [``CMakeLists.txt``](Step1/CMakeLists.txt)
  * complete
    * TODO1:
    * TODO3:

Getting Started
----------------

* [``tutorial.cxx``](Step1/tutorial.cxx)
  * allows
    * compute the square root of a number
  * | this step,
    * ❌NOT need to be edited❌

Build and Run
-------------

Once ``TODO 1`` through ``TODO 3`` have been completed, we are ready to build
and run our project! First, run the :manual:`cmake <cmake(1)>` executable or the
:manual:`cmake-gui <cmake-gui(1)>` to configure the project and then build it
with your chosen build tool.

For example, from the command line we could navigate to the
``Help/guide/tutorial`` directory of the CMake source code tree and create a
build directory:

.. code-block:: console

  mkdir Step1_build

Next, navigate to that build directory and run
:manual:`cmake <cmake(1)>` to configure the project and generate a native build
system:

.. code-block:: console

  cd Step1_build
  cmake ../Step1

Then call that build system to actually compile/link the project:

.. code-block:: console

  cmake --build .

For multi-config generators (e.g. Visual Studio), first navigate to the
appropriate subdirectory, for example:

.. code-block:: console

  cd Debug

Finally, try to use the newly built ``Tutorial``:

.. code-block:: console

  Tutorial 4294967296
  Tutorial 10
  Tutorial


**Note:** Depending on the shell, the correct syntax may be ``Tutorial``,
``./Tutorial`` or ``.\Tutorial``. For simplicity, the exercises will use
``Tutorial`` throughout.

Solution
--------

As mentioned above, a three line ``CMakeLists.txt`` is all that we need to get
up and running. The first line is to use :command:`cmake_minimum_required` to
set the CMake version as follows:

.. raw:: html

  <details><summary>TODO 1: Click to show/hide answer</summary>

.. literalinclude:: Step2/CMakeLists.txt
  :caption: TODO 1: CMakeLists.txt
  :name: CMakeLists.txt-cmake_minimum_required
  :language: cmake
  :end-before: # set the project name and version

.. raw:: html

  </details>

The next step to make a basic project is to use the :command:`project`
command as follows to set the project name:

.. raw:: html

  <details><summary>TODO 2: Click to show/hide answer</summary>

.. code-block:: cmake
  :caption: TODO 2: CMakeLists.txt
  :name: CMakeLists.txt-project

  project(Tutorial)

.. raw:: html

  </details>

The last command to call for a basic project is
:command:`add_executable`. We call it as follows:

.. raw:: html

  <details><summary>TODO 3: Click to show/hide answer</summary>

.. literalinclude:: Step2/CMakeLists.txt
  :caption: TODO 3: CMakeLists.txt
  :name: CMakeLists.txt-add_executable
  :language: cmake
  :start-after: # add the executable
  :end-before: # TODO 3:

.. raw:: html

  </details>

Exercise 2 - Specifying the C++ Standard
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

CMake has some special variables that are either created behind the scenes or
have meaning to CMake when set by project code. Many of these variables start
with ``CMAKE_``. Avoid this naming convention when creating variables for your
projects. Two of these special user settable variables are
:variable:`CMAKE_CXX_STANDARD` and :variable:`CMAKE_CXX_STANDARD_REQUIRED`.
These may be used together to specify the C++ standard needed to build the
project.

Goal
----

Add a feature that requires C++11.

Helpful Resources
-----------------

* :variable:`CMAKE_CXX_STANDARD`
* :variable:`CMAKE_CXX_STANDARD_REQUIRED`
* :command:`set`

Files to Edit
-------------

* ``CMakeLists.txt``
* ``tutorial.cxx``

Getting Started
---------------

Continue editing files in the ``Step1`` directory. Start with ``TODO 4`` and
complete through ``TODO 6``.

First, edit ``tutorial.cxx`` by adding a feature that requires C++11. Then
update ``CMakeLists.txt`` to require C++11.

Build and Run
-------------

Let's build our project again. Since we already created a build directory and
ran CMake for Exercise 1, we can skip to the build step:

.. code-block:: console

  cd Step1_build
  cmake --build .

Now we can try to use the newly built ``Tutorial`` with same commands as
before:

.. code-block:: console

  Tutorial 4294967296
  Tutorial 10
  Tutorial

Solution
--------

We start by adding some C++11 features to our project by replacing
``atof`` with ``std::stod`` in ``tutorial.cxx``. This looks like
the following:

.. raw:: html

  <details><summary>TODO 4: Click to show/hide answer</summary>

.. literalinclude:: Step2/tutorial.cxx
  :caption: TODO 4: tutorial.cxx
  :name: tutorial.cxx-cxx11
  :language: c++
  :start-after: // convert input to double
  :end-before: // TODO 6:

.. raw:: html

  </details>

To complete ``TODO 5``, simply remove ``#include <cstdlib>``.

We will need to explicitly state in the CMake code that it should use the
correct flags. One way to enable support for a specific C++ standard in CMake
is by using the :variable:`CMAKE_CXX_STANDARD` variable. For this tutorial, set
the :variable:`CMAKE_CXX_STANDARD` variable in the ``CMakeLists.txt`` file to
``11`` and :variable:`CMAKE_CXX_STANDARD_REQUIRED` to ``True``. Make sure to
add the :variable:`CMAKE_CXX_STANDARD` declarations above the call to
:command:`add_executable`.

.. raw:: html

  <details><summary>TODO 6: Click to show/hide answer</summary>

.. literalinclude:: Step2/CMakeLists.txt
  :caption: TODO 6: CMakeLists.txt
  :name: CMakeLists.txt-CXX_STANDARD
  :language: cmake
  :start-after: # specify the C++ standard
  :end-before: # configure a header file

.. raw:: html

  </details>

Exercise 3 - Adding a Version Number and Configured Header File
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Sometimes it may be useful to have a variable that is defined in your
``CMakelists.txt`` file also be available in your source code. In this case, we
would like to print the project version.

One way to accomplish this is by using a configured header file. We create an
input file with one or more variables to replace. These variables have special
syntax which looks like ``@VAR@``.
Then, we use the :command:`configure_file` command to copy the input file to a
given output file and replace these variables with the current value of ``VAR``
in the ``CMakelists.txt`` file.

While we could edit the version directly in the source code, using this
feature is preferred since it creates a single source of truth and avoids
duplication.

Goal
----

Define and report the project's version number.

Helpful Resources
-----------------

* :variable:`<PROJECT-NAME>_VERSION_MAJOR`
* :variable:`<PROJECT-NAME>_VERSION_MINOR`
* :command:`configure_file`
* :command:`target_include_directories`

Files to Edit
-------------

* ``CMakeLists.txt``
* ``tutorial.cxx``
* ``TutorialConfig.h.in``

Getting Started
---------------

Continue to edit files from ``Step1``. Start on ``TODO 7`` and complete through
``TODO 12``. In this exercise, we start by adding a project version number in
``CMakeLists.txt``. In that same file, use :command:`configure_file` to copy a
given input file to an output file and substitute some variable values in the
input file content.

Next, create an input header file ``TutorialConfig.h.in`` defining version
numbers which will accept variables passed from :command:`configure_file`.

Finally, update ``tutorial.cxx`` to print out its version number.

Build and Run
-------------

Let's build our project again. As before, we already created a build directory
and ran CMake so we can skip to the build step:

.. code-block:: console

  cd Step1_build
  cmake --build .

Verify that the version number is now reported when running the executable
without any arguments.

Solution
--------

In this exercise, we improve our executable by printing a version number.
While we could do this exclusively in the source code, using ``CMakeLists.txt``
lets us maintain a single source of data for the version number.

First, we modify the ``CMakeLists.txt`` file to use the
:command:`project` command to set both the project name and version number.
When the :command:`project` command is called, CMake defines
``Tutorial_VERSION_MAJOR`` and ``Tutorial_VERSION_MINOR`` behind the scenes.

.. raw:: html

  <details><summary>TODO 7: Click to show/hide answer</summary>

.. literalinclude:: Step2/CMakeLists.txt
  :caption: TODO 7: CMakeLists.txt
  :name: CMakeLists.txt-project-VERSION
  :language: cmake
  :start-after: # set the project name and version
  :end-before: # specify the C++ standard

.. raw:: html

  </details>

Then we used :command:`configure_file` to copy the input file with the
specified CMake variables replaced:

.. raw:: html

  <details><summary>TODO 8: Click to show/hide answer</summary>

.. literalinclude:: Step2/CMakeLists.txt
  :caption: TODO 8: CMakeLists.txt
  :name: CMakeLists.txt-configure_file
  :language: cmake
  :start-after: # to the source code
  :end-before: # TODO 2:

.. raw:: html

  </details>

Since the configured file will be written into the project binary
directory, we must add that directory to the list of paths to search for
include files.

**Note:** Throughout this tutorial, we will refer to the project build and
the project binary directory interchangeably. These are the same and are not
meant to refer to a ``bin/`` directory.

We used :command:`target_include_directories` to specify
where the executable target should look for include files.

.. raw:: html

  <details><summary>TODO 9: Click to show/hide answer</summary>

.. literalinclude:: Step2/CMakeLists.txt
  :caption: TODO 9: CMakeLists.txt
  :name: CMakeLists.txt-target_include_directories
  :language: cmake
  :start-after: # so that we will find TutorialConfig.h

.. raw:: html

  </details>

``TutorialConfig.h.in`` is the input header file to be configured.
When :command:`configure_file` is called from our ``CMakeLists.txt``, the
values for ``@Tutorial_VERSION_MAJOR@`` and ``@Tutorial_VERSION_MINOR@`` will
be replaced with the corresponding version numbers from the project in
``TutorialConfig.h``.

.. raw:: html

  <details><summary>TODO 10: Click to show/hide answer</summary>

.. literalinclude:: Step2/TutorialConfig.h.in
  :caption: TODO 10: TutorialConfig.h.in
  :name: TutorialConfig.h.in
  :language: c++

.. raw:: html

  </details>

Next, we need to modify ``tutorial.cxx`` to include the configured header file,
``TutorialConfig.h``.

.. raw:: html

  <details><summary>TODO 11: Click to show/hide answer</summary>

.. code-block:: c++
  :caption: TODO 11: tutorial.cxx

  #include "TutorialConfig.h"

.. raw:: html

  </details>

Finally, we print out the executable name and version number by updating
``tutorial.cxx`` as follows:

.. raw:: html

  <details><summary>TODO 12: Click to show/hide answer</summary>

.. literalinclude:: Step2/tutorial.cxx
  :caption: TODO 12 : tutorial.cxx
  :name: tutorial.cxx-print-version
  :language: c++
  :start-after: {
  :end-before: // convert input to double

.. raw:: html

  </details>
