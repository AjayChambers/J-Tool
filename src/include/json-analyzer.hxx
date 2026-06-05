#pragma once
#include <json-buffer.hxx>


namespace JT
{
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

      public:
        explicit JsonAnalyzer(JsonBuffer);
        explicit JsonAnalyzer(const std::string &);
        explicit JsonAnalyzer(std::vector<char> &&);

        void analyze();
    };
} // namespace JT
