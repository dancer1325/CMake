CMake
*****

Introduction
============

* CMake
  * == ⭐️build system generator⭐️
    * cross-platform,
    * open-source 
  * [hosted](https://cmake.org)
  * maintained by [Kitware](https://www.kitware.com/cmake) + community 
  * [documentation](Help/index.md)
  * [wiki](https://gitlab.kitware.com/cmake/community/-/wikis/home)
  * [forum](https://discourse.cmake.org)

Building CMake
==============

Supported Platforms
-------------------

* Microsoft Windows
* Apple macOS
* Linux
* FreeBSD
* OpenBSD
* Solaris
* AIX
* OTHER UNIX-like OS may work too

Building CMake with CMake
-------------------------

* TODO: You can build CMake as any other project with a CMake-based build system:
run an already-installed CMake on this source tree with your preferred
generator and options.  Then build it and install it.

To build the documentation, install `Sphinx`_ and configure CMake with
``-DSPHINX_HTML=ON`` and/or ``-DSPHINX_MAN=ON`` to enable the "html" or
"man" builder.  Add ``-DSPHINX_EXECUTABLE=/path/to/sphinx-build`` if the
tool is not found automatically.

To run the test suite, run ``ctest`` in the CMake build directory after
building.  See the `CMake Testing Guide`_ for details.

.. _`Sphinx`: https://sphinx-doc.org
.. _`CMake Testing Guide`: Help/dev/testing.rst

Building CMake from Scratch
---------------------------

UNIX/Mac OSX/MinGW/MSYS/Cygwin
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You need to have a C++ compiler (supporting C++11) and a ``make`` installed.
Run the ``bootstrap`` script you find in the source directory of CMake.
You can use the ``--help`` option to see the supported options.
You may use the ``--prefix=<install_prefix>`` option to specify a custom
installation directory for CMake.  Once this has finished successfully,
run ``make`` and ``make install``.

For example, if you simply want to build and install CMake from source,
you can build directly in the source tree::

  $ ./bootstrap && make && sudo make install

Or, if you plan to develop CMake or otherwise run the test suite, create
a separate build tree::

  $ mkdir build && cd build
  $ ../bootstrap && make

Windows
^^^^^^^

There are two ways for building CMake under Windows:

1. Compile with MSVC from VS 2015 or later.
   You need to download and install a binary release of CMake.  You can get
   these releases from the `CMake Download Page`_.  Then proceed with the
   instructions above for `Building CMake with CMake`_.

2. Bootstrap with MinGW under MSYS2.
   Download and install `MSYS2`_.  Then install the required build tools::

     $ pacman -S --needed git base-devel mingw-w64-x86_64-gcc

   and bootstrap as above.

.. _`CMake Download Page`: https://cmake.org/download
.. _`MSYS2`: https://www.msys2.org/

Reporting Bugs
==============

* steps
  1. read the [CONTRIBUTING.rst](CONTRIBUTING.rst)
  2. find or post | [CMake Discourse Forum](https://discourse.cmake.org)
  3. if it's NOT found -> [CMake Issue Tracker](https://gitlab.kitware.com/cmake/cmake/-/issues)
