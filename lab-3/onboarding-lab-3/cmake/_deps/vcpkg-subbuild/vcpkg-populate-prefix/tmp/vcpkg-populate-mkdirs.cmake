# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/_deps/vcpkg-src")
  file(MAKE_DIRECTORY "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/_deps/vcpkg-src")
endif()
file(MAKE_DIRECTORY
  "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/_deps/vcpkg-build"
  "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/_deps/vcpkg-subbuild/vcpkg-populate-prefix"
  "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/_deps/vcpkg-subbuild/vcpkg-populate-prefix/tmp"
  "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/_deps/vcpkg-subbuild/vcpkg-populate-prefix/src/vcpkg-populate-stamp"
  "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/_deps/vcpkg-subbuild/vcpkg-populate-prefix/src"
  "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/_deps/vcpkg-subbuild/vcpkg-populate-prefix/src/vcpkg-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/_deps/vcpkg-subbuild/vcpkg-populate-prefix/src/vcpkg-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/_deps/vcpkg-subbuild/vcpkg-populate-prefix/src/vcpkg-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
