#pragma once
#include <filesystem>
#include <json-buffer.hxx>

namespace fs = std::filesystem;

namespace JT
{
    using Path = fs::path;

    class JsonFile
    {
      public:
        using value_type = char;
        using size_type  = std::size_t;
        using pointer    = const char *;
        using reference  = const char &;
        using JsonBuffer = JT::JsonBuffer;

      private:
        Path path;
        JsonBuffer buff;

      public:
        // Constructors
        JsonFile(const Path &path);
        explicit JsonFile(const std::string &path);
        explicit JsonFile(const char *path);

        // Read/Write Operations
        void append(const std::string &json) const;
        void write(const std::string &json) const;
        void read() const;

        size_type size() const;
        pointer data() const;

        JsonBuffer toBuffer() const;
        std::string toString() const;
    };
} // namespace JT
