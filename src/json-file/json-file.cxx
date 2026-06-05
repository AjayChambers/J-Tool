#include <fstream>
#include <json-file.hxx>


using size_type = JT::JsonBuffer::size_type;
using pointer   = JT::JsonBuffer::pointer;

namespace JT
{
    /*************************************************************
     * @brief "Constructs a JsonFile object by reading the
     *   contents of the file at the specified path."
     * @param path The path to the file to be read.
     ***********************************************************/
    JsonFile::JsonFile(const std::string &path)
      : JsonFile(Path(path)) {}




    /*************************************************************
     * @brief "Constructs a JsonFile object by reading the
     *   contents of the file at the specified path."
     * @param path The path to the file to be read.
     ***********************************************************/
    JsonFile::JsonFile(const char *path)
      : JsonFile(Path(path)) {}




    /*************************************************************
     * @brief "Constructs a JsonFile object by reading the
     *   contents of the file at the specified path."
     * @param path The path to the file to be read.
     ***********************************************************/
    JsonFile::JsonFile(const Path &path)
      : path(path),
        buff(
          [&]()
          {
              std::ifstream file(path, std::ios::binary);

              if (!file) {
                  throw std::runtime_error("Could not open file");
              }

              return std::string(std::istreambuf_iterator<char>(file),
                std::istreambuf_iterator<char>());
          }()) {}



    /*************************************************************
     * @brief "Reads the contents of the file associated with this
     *   JsonFile object and returns it as a string."
     * @throw std::runtime_error if the file cannot be opened or
     *   read
     *************************************************************/
    void JsonFile::read() const {
        std::ifstream file(path, std::ios::binary);

        if (!file) {
            throw std::runtime_error("Could not open file");
        }

        auto buffer = std::vector<char>(fs::file_size(path));

        auto STREAM_MAX =
          static_cast<std::uintmax_t>(std::numeric_limits<std::streamsize>::max());

        if (buffer.size() > STREAM_MAX) {
            throw std::runtime_error("File too large to read");
        }

        if (!file.read(buffer.data(), static_cast<std::streamsize>(buffer.size()))) {
            throw std::runtime_error("Error reading file");
        }
    }




    size_type JsonFile::size() const {
        return buff.size();
    }




    pointer JsonFile::data() const {
        return buff.data();
    }



    JsonBuffer JsonFile::toBuffer() const {
        return JsonBuffer(std::vector<char>(buff.begin(), buff.end()));
    }


    std::string JsonFile::toString() const {
        return std::string(buff.begin(), buff.end());
    }
} // namespace JT
