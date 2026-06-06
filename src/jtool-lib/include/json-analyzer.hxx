#pragma once
#include "../../json-buffer/include/json-buffer.hxx"


namespace JT
{


    enum class TOKEN_TYPE {
        // Punctuation/Delimiters = 1 - 6
        COLON     = 1, // K/V Pair Assignment Operator  "COLON" = 1
        COMMA     = 2, // K/V Pair Termination Operator "COMMA" = 2
        OPEN_OBJ  = 3, // OBJECT CURLY BRACE (OPEN = 3)
        CLOSE_OBJ = 4, // OBJECT CURLY BRACE (CLOSE = 4)
        OPEN_ARR  = 5, // ARRAY BRACKET (OPEN = 21)
        CLOSE_ARR = 6, // ARRAY BRACKET (CLOSE = 22)

        // Dynamic Values = 21 - 24
        STRING  = 21, // JSON VALUE (STRING = 51)
        NUMBER  = 22, // JSON VALUE (NUMBER = 52)
        BASE_8  = 23, // JSON VALUE (OCTAL NUMBER = 53)
        BASE_16 = 24, // JSON VALUE (HEX NUMBER = 54)

        // Literals = 31 - 33
        _TRUE  = 31, // JSON LITERALS (TRUE = 41
        _FALSE = 32, // JSON LITERALS (FALSE = 42)
        _NULL  = 33, // JSON LITERALS (NULL = 43)

    };





    struct Token {
        TOKEN_TYPE type;
        std::string value;
        Token(TOKEN_TYPE type, const std::string &value = "")
          : type(type),
            value(value) {}
    };




    struct TokenGenerator {
        static auto colon() -> Token { return Token(TOKEN_TYPE::COLON, ":"); }
        static auto comma() -> Token { return Token(TOKEN_TYPE::COMMA, ","); }
        static auto object_open() -> Token { return Token(TOKEN_TYPE::OPEN_OBJ, "{"); }
        static auto object_close() -> Token { return Token(TOKEN_TYPE::CLOSE_OBJ, "}"); }
        static auto array_open() -> Token { return Token(TOKEN_TYPE::OPEN_ARR, "["); }
        static auto array_close() -> Token { return Token(TOKEN_TYPE::CLOSE_ARR, "]"); }
        static auto trueToken() -> Token { return Token(TOKEN_TYPE::_TRUE, "true"); }
        static auto falseToken() -> Token { return Token(TOKEN_TYPE::_FALSE, "false"); }
        static auto nullToken() -> Token { return Token(TOKEN_TYPE::_NULL, "null"); }
    };




    class JsonAnalyzer
    {
      public:
        using value_type = char;
        using size_type  = JsonBuffer::size_type;
        using pointer    = JsonBuffer::pointer;
        using reference  = JsonBuffer::reference;
        using Iterator   = JsonBuffer::Iterator;

      private:
        JsonBuffer buffer;
        std::vector<Token> tokens;

      public:
        explicit JsonAnalyzer(JsonBuffer);
        explicit JsonAnalyzer(const std::string &);
        explicit JsonAnalyzer(std::vector<char> &&);

        void analyze();
    };

    /*
        TODO: Add abstract syntax tree that represents the JSON structure.
        Each string contained in the AST vector represents a line in the JSON file.
        The strings should be appended with meta data that indicates the type of JSON
        element that the line represents.
        For example:
            "[OBJECT OPEN]"
            "[OBJECT CLOSE]"
            "[ARRAY OPEN]"
            "[ARRAY CLOSE]"
            "[STRING]: String here".
            "[NUMBER]: Number here".
            "[BOOL]: either true or false here".
            "[NULL]".
        FUNCTION SIGNATURE:
            std::vector<std::string> generateAbstractSyntaxTree(const std::vector<Token>
       &tokens);
    */
} // namespace JT
