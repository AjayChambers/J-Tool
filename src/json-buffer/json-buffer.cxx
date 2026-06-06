#include "./include/json-buffer.hxx"

namespace JT
{
    using Iterator  = JsonBuffer::Iterator;
    using size_type = JsonBuffer::size_type;
    using pointer   = JsonBuffer::pointer;



    /************************************************************
     * @brief Constructs a JsonBuffer object by copying the
     *  contents of the provided JSON string into an internal
     *  buffer.
     ************************************************************/
    JsonBuffer::JsonBuffer(const std::string &json)
      : buff(json.begin(), json.end()),
        data_(buff.data()) {}



    /************************************************************
     * @brief Constructs a JsonBuffer object by moving the
     *  contents of the provided JSON vector into an internal
     *  buffer.
     ************************************************************/
    JsonBuffer::JsonBuffer(std::vector<char> &&json)
      : buff(std::move(json)),
        data_(buff.data()) {}



    /************************************************************
     * @brief Returns an iterator pointing to the first character
     *  in the buffer.
     ************************************************************/
    Iterator JsonBuffer::begin() const {
        return Iterator(buff.data(),
          buff.data() + buff.size(),
          buff.data());
    }




    /************************************************************
     * @brief Returns an iterator pointing to one past the last
     *  character in the buffer.
     ************************************************************/
    Iterator JsonBuffer::end() const {
        return Iterator(buff.data(),
          buff.data() + buff.size(),
          buff.data() + buff.size());
    }



    /************************************************************
     * @brief Returns the number of characters in the buffer.
     ************************************************************/
    size_type JsonBuffer::size() const {
        return buff.size();
    }



    /************************************************************
     * @brief Returns a pointer to the underlying character array
     *  of the buffer.
     ************************************************************/
    pointer JsonBuffer::data() const {
        return data_;
    }



    /************************************************************
     * @brief Returns the buffer's contents as type std::string.
     ************************************************************/
    std::string JsonBuffer::to_string() const {
        return std::string(buff.data(), buff.size());
    }
} // namespace JT
