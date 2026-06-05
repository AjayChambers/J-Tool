/*
 * TEST_DATA is injected by the CMake function "target_compile_definitions"
 * See "test/CMakeLists.txt"
 *
 * `````````````````````````````````````````````````````````````````
 *     target_compile_definitions(
 *       ${J_FILE_TEST} PRIVATE
 *       TEST_DATA="${JF_TEST_DATA}")`
 * `````````````````````````````````````````````````````````````````
 * */
#ifndef TEST_DATA
#define TEST_DATA "D:/J-Tool/test/pseudo-data/json-file-test-data.json"
#endif

#include <fstream>
#include <gtest/gtest.h>
#include <json-buffer.hxx>
#include <json-file.hxx>
#include <sstream>
#include <string>

using namespace JT;

TEST(JsonFileClass, CanReadJsonFiles)
{
    std::string expected   = "";
    std::string actual     = "";
    const std::string path = TEST_DATA;

    std::ifstream file(path, std::ios::in | std::ios::binary);
    ASSERT_TRUE(file.is_open());

    std::ostringstream ss;
    ss << file.rdbuf();
    auto contents = ss.str();
    ASSERT_FALSE(contents.empty());

    EXPECT_EQ(expected, actual);
}
