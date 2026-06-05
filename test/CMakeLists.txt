#---------------------------------------------------------------#
#
# J-TOOL JSON Analyzer, formatter, schema validator, and more.
# Copyright (C) 2026 "Andrew Jay Chambers Jr"
#
#   This program is free software: you can redistribute it and/or
#   modify it under the terms of the GNU General Public License
#   as published by the Free Software Foundation, either version
#   3 of the License, or (at your option) any later version.
#
#   This program is distributed in the hope that it will be
#   useful, but WITHOUT ANY WARRANTY; without even the implied
#   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#   PURPOSE. See the GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public
#   License along with this program. If you did not receive a
#   copy visit <"https://www.gnu.org/licenses/">
#----------------------------------------------------------------
#
# FILE: "test/CMakeLists.txt"
# LIC:  "GPL-3.0"
# AUTH: "Ajay Chambers"
# REPO: "https://GitHub.com/AjayChambers/J-Tool"
# DESC: "Project unit testing configuration"
#----------------------------------------------------------------

include("Fetch-GoogleTest")
include("Add-Unit-Test")
include("CTest")
fetch_googletest("v1.17.0")
enable_testing()

# TESTING DATA
set(DATA_FILE_0 ${JT_TEST_DIR}/pseudo-data/json-file.test-data.json)



#================================================================
# Unit Test: "JsonBuffer"
#================================================================
add_unit_test(
  json_buffer_test
  "json-buffer.test.cxx"
  "json-buffer"
  "${JT_TEST_BIN_DIR}")

target_link_libraries(json_buffer_test PUBLIC
  "GTest::gtest_main;json_buffer")



#================================================================
# Unit Test: "JsonFile"
#===============================================================
add_unit_test(
  json_file_test
  "json-file.test.cxx"
  "json-file"
  "${JT_TEST_BIN_DIR}")

target_link_libraries(json_file_test PUBLIC
  "GTest::gtest_main;json_buffer;json_file")

target_compile_definitions(
  json_file_test
  PUBLIC
  TEST_DATA="${DATA_FILE_0}")


# !! DO NOT CHANGE ANY OF THE LINES BELOW THIS POINT. !!
# !! DOING SO WILL BREAK THE 'JSON-FILE' unit test    !!,
file(WRITE "${DATA_FILE_0}"
  "{\n"
  "  \"Letters\": [\"A\", \"B\", \"C\", \"D\", \"E\"],\n"
  "  \"Numbers\": [1, 2, 3, 4, 5],\n"
  "  \"Nested Object\": {\n"
  "    \"Level\": 2,\n"
  "    \"Nested Object\": {\n"
  "      \"Level\": 3,\n"
  "      \"Last Key\": \"Value Pair\"\n"
  "    }\n"
  "  }\n"
  "}")