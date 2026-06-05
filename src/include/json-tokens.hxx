#pragma once
#include <string>


namespace JT
{
    enum class TOKEN_TYPE {
        L_BRACE,   // {
        R_BRACE,   // }
        L_BRACKET, // [
        R_BRACKET, // ]
        COLON,     // :
        COMMA,     // ,
        STRING,    // "..."
        NUMBER,    // 123, -123, 1.23, etc.
        TRUE_,     // true
        FALSE_,    // false
        NULL_      // null
    };


    struct Token {
        TOKEN_TYPE type;
        std::string value;

        Token(TOKEN_TYPE type, const std::string &value = "")
            : type(type),
              value(value) {}
    };
} // namespace JT
