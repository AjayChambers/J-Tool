######################################################################
#
#  J-TOOL: JSON Analyzer, Parser & Formatter
#  COPYRIGHT (C) 2026 ANDREW JAY CHAMBERS
#
#    This program is free software: you can redistribute it and/or
#    modify it under the terms of the GNU General Public License as
#    published by the Free Software Foundation, either version 3 of
#    the License, or (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public
#    License with this program. If you did not receive a copy,
#    see <https://www.gnu.org/licenses/>.
#
######################################################################
#
#  FILENAME:    "CMakeLists.txt"
#  DIRECTORY:   "J-Tool"
#  AUTHOR:      "Andrew Jay Chambers ('Ajay.Chambers@outlook.com')"
#  REPOSITORY:  "https://GitHub.com/GitHub_UID/{Project_Name}
#  LICENSE:     "GNU General Public License v3.0 (GPL v3.0)"
#  DESCRIPTION:
#    "This file is the initial script that CMake runs when J-Tool is
#     built. It's responsible for defining the project, its core
#     structure, as well as the CMake version and C++ standard that
#     J-Tool will adhere to."
#
######################################################################
CMAKE_MINIMUM_REQUIRED(VERSION 4.3.2)
list(PREPEND CMAKE_MODULE_PATH
    "cmake/scripts/cache-var-mod"
    "cmake/scripts")

include("CMakeGlobals.cmake")
#----------------------------------------------------------------
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
#
#----------------------------------------------------------------
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
