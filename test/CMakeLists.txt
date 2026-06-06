include("Fetch-GoogleTest")
include("Add-Unit-Test")
include("CTest")
fetch_googletest("v1.17.0")
enable_testing()



#================================================================
# Unit Test: "JsonBuffer"
#================================================================
add_unit_test(
  json_buffer_test
  json-buffer.test.cxx
  json-buffer
  ${TEST_RUNTIME_DIR_})

target_include_directories(json_buffer_test PRIVATE
  ${SOURCE_DIR_}/json-buffer/include
  ${INCLUDE_DIR_})

target_link_libraries(json_buffer_test PUBLIC
  "GTest::gtest_main;json_buffer")




#================================================================
# Unit Test: "JsonFile"
#===============================================================
add_unit_test(
  json_file_test
  json-file.test.cxx
  json-file
  ${TEST_RUNTIME_DIR_})

target_include_directories(json_file_test PRIVATE
  ${SOURCE_DIR_}/json-buffer/include
  ${SOURCE_DIR_}/json-file/include
  ${INCLUDE_DIR_})

target_link_libraries(json_file_test PUBLIC
  "GTest::gtest_main;json_buffer;json_file")

set(DATA_FILE_0
  "${TEST_DIR_}/pseudo-data/json-file.test-data.json")

target_compile_definitions(json_file_test PUBLIC
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