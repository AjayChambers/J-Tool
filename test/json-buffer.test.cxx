#include <gtest/gtest.h>
#include <json-buffer.hxx>
#include <string>

using namespace JT;

TEST(JsonBufferClass, InitializesWithString) {
    std::string someJson = "{\"key\": \"value\"}";
    JsonBuffer json(someJson);

    EXPECT_EQ(json.to_string(), someJson);
}


TEST(JsonBufferIterator, IteratesOverString) {
    std::string someJson = "{\"key\": \"value\"}";
    JsonBuffer json(someJson);

    auto iter = json.begin();
    auto end  = json.end();

    std::string collected;

    while (iter != end) {
        collected += *iter;
        ++iter;
    }

    EXPECT_EQ(collected, someJson);
}


TEST(JsonBufferIterator, OperatorsAccess) {
    std::string someJson = "{\"key\": \"value\"}";
    JsonBuffer json(someJson);

    auto iter = json.begin();

    EXPECT_EQ(*iter, '{');
    EXPECT_EQ(iter[1], '"');
    EXPECT_EQ(iter.at(2), 'k');
}




TEST(JsonBufferIterator, OperatorsPostIncrementPreIncrement) {
    std::string s = "abc";
    JsonBuffer json(s);

    auto iter = json.begin();

    // Pre-increment
    auto &pre = ++iter;
    EXPECT_EQ(*pre, 'b');
    EXPECT_EQ(*iter, 'b');

    // Post-increment
    auto post = iter++;
    EXPECT_EQ(*post, 'b');
    EXPECT_EQ(*iter, 'c');
}




TEST(JsonBufferIterator, OperatorsPostDecrementPreDecrement) {
    std::string s = "abc";
    JsonBuffer json(s);

    auto iter = json.begin() + 2; // points to 'c'

    // Pre-decrement
    auto &pre = --iter;
    EXPECT_EQ(*pre, 'b');
    EXPECT_EQ(*iter, 'b');

    // Post-decrement
    auto post = iter--;
    EXPECT_EQ(*post, 'b');
    EXPECT_EQ(*iter, 'a');
}




//  RAIArithmetic = "Random Access Iterator Arithmetic"
TEST(JsonBufferIterator, OperatorsRAIArithmetic) {
    std::string s = "abcdef";
    JsonBuffer json(s);

    auto iter = json.begin();

    EXPECT_EQ(*(iter + 3), 'd');
    EXPECT_EQ(*(3 + iter), 'd');
    EXPECT_EQ(*(iter += 2), 'c');
    EXPECT_EQ(*(iter -= 1), 'b');

    auto iter2 = json.begin() + 5;
    EXPECT_EQ(iter2 - iter, 4);
}




TEST(JsonBufferIterator, OperatorsEqualityAndComparison) {
    std::string s = "abcdef";
    JsonBuffer json(s);

    auto a = json.begin();
    auto b = json.begin() + 3;

    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(b > a);
    EXPECT_TRUE(b >= a);
    EXPECT_TRUE(a != b);

    auto c = json.begin();
    EXPECT_TRUE(a == c);
}




TEST(JsonBufferIterator, FuncMemberAtThrowsOutOfRange) {
    std::string s = "abc";
    JsonBuffer json(s);

    auto iter = json.begin();

    EXPECT_NO_THROW(iter.at(2));
    EXPECT_THROW(iter.at(3), std::out_of_range);
}
