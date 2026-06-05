list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/scripts")
include("${CMAKE_SOURCE_DIR}/cmake/scripts/cache-var.cmake")
#
#
#############################################
# CACHED STRING VARIABLES
#############################################
cache_var(
  JT_DESCRIPTION
  "J-Tool is a set of tools for working with, and manipulating, JSON"
  "J-Tool's description"
  FORCE)

cache_var(
  JT_VERSION
  "0.1.0"
  "J-Tool's version number"
  FORCE)
#
#
#############################################
# CACHED DIRECTORY PATHS
#############################################
cache_path(
  JT_ROOTDIR
  "${CMAKE_SOURCE_DIR}"
  "J-Tool project's root directory"
  FORCE)

cache_path(
  JT_INCLUDE_DIR
  "${JT_ROOTDIR}/src/include"
  "J-Tool project's include directory"
  FORCE)

cache_path(
  JT_TEST_DIR
  "${JT_ROOTDIR}/test"
  "Path to J-Tool unit-test source code"
  FORCE)

cache_path(
  JT_BUILD_DIR
  "${CMAKE_BINARY_DIR}/bin"
  "J-Tool project's build directory"
  FORCE)

cache_path(
  JT_BIN_DIR
  "${CMAKE_BINARY_DIR}/bin"
  "Directory where J-Tool executable binaries are built & stored"
  FORCE)

cache_path(
  JT_TEST_BIN_DIR
  "${CMAKE_BINARY_DIR}/test/bin"
  "Directory where J-Tool's unit-tests are built & stored"
  FORCE)

cache_path(
  JT_LIB_DIR
  "${CMAKE_BINARY_DIR}/lib"
  "Directory where J-Tool's libraries are built & stored"
  FORCE)

cache_path(
  JT_CMAKE_MODULES
  "${JT_ROOTDIR}/cmake"
  "Directory where J-Tool's CMake modules are stored"
  FORCE)
