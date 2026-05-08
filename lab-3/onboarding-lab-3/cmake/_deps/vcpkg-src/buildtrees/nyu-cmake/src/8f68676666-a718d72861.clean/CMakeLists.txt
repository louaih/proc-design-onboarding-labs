cmake_minimum_required(VERSION 3.25)

project(nyu-cmake VERSION 1.2.0)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/nyu-cmake-config-version.cmake
  COMPATIBILITY AnyNewerVersion
)

install(FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/nyu-verilog.cmake
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/nyu-test.cmake
  ${CMAKE_CURRENT_SOURCE_DIR}/nyu-cmake-config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/nyu-cmake-config-version.cmake
  DESTINATION ${CMAKE_INSTALL_DATADIR}/nyu-cmake
)
