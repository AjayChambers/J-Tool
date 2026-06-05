#################################################################
# J-TOOL: JSON Analyzer, Parser & Formatter
# Copyright (C) 2026 "Andrew Jay Chambers Jr"
#
# This program is free software: you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation, either version 3 of
# the License, or at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public
# License along with this program. If you did not receive a copy
# visit <"https://www.gnu.org/licenses/">
#
#################################################################
#
# FILE: "jt-unit-test.cmake"
# LIC:  "GPL-3.0"
# AUTH: "Andrew J Chambers Jr"
# REPO: "https://GitHub.com/AjayChambers/J-Tool"
# FILE DESCRIPTION:
#   "This file contains the functions that make up the unit-test
#   CMake module custom written for the J-Tool project. The mod
#   requires GoogleTest and J-Tool's CMake-Globals.cmake config
#   file to work properly."
#################################################################

#################################################################
# FUNCTION: "add_unit_test"
# ARGUMENTS:
#   * TARGET_NAME - "The name of the test target to be created."
#   * BINARY_NAME - "The test's executable name used in the
#      terminal/console when executing the test."
#   * FILENAME - "The test's source filename."
# DESCRIPTION: "Configures test targets for unit testing. The
#   function appends the test's executable name with a unique
#   prefix to avoid naming conflicts with the project's 'src'
#   binaries and libraries."
#################################################################
function(add_unit_test  TARGET_NAME  FILENAME  BINARY_NAME  BIN_DIR)
  string(PREPEND BINARY_NAME "__JT-TEST__")
  add_executable(${TARGET_NAME} "${JT_TEST_DIR}/${FILENAME}")
  add_test(NAME ${TARGET_NAME} COMMAND ${BINARY_NAME})
  gtest_discover_tests(${TARGET_NAME})
  set_target_properties(
      ${TARGET_NAME} PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
      OUTPUT_NAME ${BINARY_NAME})
endfunction()