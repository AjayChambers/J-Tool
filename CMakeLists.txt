#================================================================
# J-TOOL, JSON Analyzer, Parser & Formatter
# Copyright (C) 2026 Andrew Jay Chambers
#
#   Licensed under the GNU General Public License v3.0. To view
#   a copy of the license (@see "LICENSE.md") in this project's
#   root directory or visit <"https://www.gnu.org/licenses/">.
#
# REPOSITORY: "https://GitHub.com/AjayChambers/J-Tool"
# ISSUE/BUG:  "https://GitHub.com/AjayChambers/J-Tool/issues"
# CONTACT:    "Ajay.Chambers@Outlook.com"
#================================================================
# FILE'S META DETAILS
#   FILENAME:  "CMakeLists.txt"
#   AUTHOR(s): "Ajay Chambers"
#   FILE DESC:
#     "This file is the initial script that CMake runs when
#     J-TOOL is built. It's responsible for defining the project,
#     calling the first level of subdirectory's CMakeLists.txt
#     files. It also includes the 'CMakeGlobals.cmake' script
#     which contains a set of global variables that can be used
#     throughout the entire project."
#================================================================
CMAKE_MINIMUM_REQUIRED(VERSION 4.3.2)

list(PREPEND CMAKE_MODULE_PATH
    "cmake/scripts/cache-var-mod"
    "cmake/scripts")

include("CMakeGlobals.cmake")
#================================================================
# "CMakeGlobals.cmake"
# The CMake script included above contains a set of CMake global
# variables that can be used in CMakeLists.txt files throughout
# the entire J-Tool project.
#
#   AVAILABLE VARS:
#     * PROJ_NAME_
#     * PROJ_VER_
#     * PROJ_DESC_
#     * ROOT_DIR_
#     * INCLUDE_DIR_
#     * SOURCE_DIR_
#     * BUILD_DIR_
#     * RUNTIME_DIR_
#     * ARCHIVE_DIR_
#     * LIBRARY_DIR_
#     * TEST_DIR_
#     * TEST_RUNTIME_DIR_
#     * MODULE_DIR_
#================================================================

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("J-TOOL"
  VERSION ${PROJ_VER_}
  DESCRIPTION ${PROJ_DESC_}
  LANGUAGES CXX)

include_directories(${INCLUDE_DIR_})
add_subdirectory("src")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  list(PREPEND CMAKE_MODULE_PATH ${MODULE_DIR_}/test-mod)
  add_subdirectory(test)
endif()
