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
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include("CMakeGlobals.cmake")

list(PREPEND
  CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/scripts")

project(
  "J-Tool"
  VERSION ${JT_VERSION}
  DESCRIPTION ${JT_DESCRIPTION}
  LANGUAGES CXX)

include_directories(${JT_INCLUDE_DIR})

add_subdirectory(src)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  # Inform CMake where the test modules are located
  list(PREPEND
    CMAKE_MODULE_PATH
    "${CMAKE_SOURCE_DIR}/cmake/scripts/test-mod")
  add_subdirectory(test) # Will build all J-Tool unit tests
endif()
