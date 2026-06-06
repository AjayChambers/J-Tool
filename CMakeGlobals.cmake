list(PREPEND CMAKE_MODULE_PATH
    "${CMAKE_SOURCE_DIR}/cmake/scripts"
    "${CMAKE_SOURCE_DIR}/cmake/scripts/cache-var-mod")

include("${CMAKE_SOURCE_DIR}/cmake/scripts/cache-var-mod/cache-var.cmake")




#############################################
# CACHED STRING VARIABLES
#############################################
cache_var(
  PROJ_NAME_
  "J-TOOL"
  "The name of the project."
  FORCE)


cache_var(
  PROJ_DESC_
  "J-Tool is a set of tools for working with, and manipulating, JSON"
  "The description of the project."
  FORCE)


cache_var(
  PROJ_VER_
  "0.1.0"
  "The version number of the project."
  FORCE)




#############################################
# CACHED DIRECTORY PATHS
#############################################
cache_path(
  ROOT_DIR_
  "${CMAKE_SOURCE_DIR}"
  "Project root directory (contains the main CMakeLists.txt file)."
  FORCE)


cache_path(
  INCLUDE_DIR_
  "${CMAKE_SOURCE_DIR}/include"
  "Project include directory where public headers (.hxx) are stored."
  FORCE)


cache_path(
  SOURCE_DIR_
  "${CMAKE_SOURCE_DIR}/src"
  "Project source directory."
  FORCE)


cache_path(
  BUILD_DIR_
  "${CMAKE_BINARY_DIR}"
  "Project build directory."
  FORCE)


cache_path(
  RUNTIME_DIR_
  "${CMAKE_BINARY_DIR}/bin"
  "The location where executable binaries are built & stored."
  FORCE)


cache_path(
  ARCHIVE_DIR_
  "${CMAKE_BINARY_DIR}/lib"
  "The location where static libs are built & stored."
  FORCE)


cache_path(
  LIBRARY_DIR_
  "${CMAKE_BINARY_DIR}/lib"
  "The location where dynamic libs (.dll, .so, .dylib) are built & stored."
  FORCE)


cache_path(
  TEST_DIR_
  "${CMAKE_SOURCE_DIR}/test"
  "Project test directory where unit-test source files are stored."
  FORCE)


cache_path(
  TEST_RUNTIME_DIR_
  "${CMAKE_BINARY_DIR}/test/bin"
  "Location where unit-test executable binaries are built & stored."
  FORCE)


cache_path(
  MODULE_DIR_
  "${CMAKE_SOURCE_DIR}/cmake/scripts"
  "Project CMake module directory where custom CMake scripts are stored."
  FORCE)
