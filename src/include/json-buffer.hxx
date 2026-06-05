#pragma once
#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>


namespace JT
{
    /************************************************************
     * @brief "An immutable buffer class that encapsulates a
     *  contiguous block of memory containing JSON data. The
     *  class provides an iterator interface for traversing the
     *  JSON data, as well as methods for accessing the size and
     *  raw data of the buffer."
     ************************************************************/
    class JsonBuffer
    {
      public:
        class Iterator; // Forward declaration
        using value_type = char;
        using size_type  = std::size_t;
        using pointer    = const char *;
        using reference  = const char &;

      private:
        const std::vector<char> buff;
        pointer data_;

      public:
        // Constructors
        JsonBuffer(const std::string &);
        JsonBuffer(std::vector<char> &&);
        JsonBuffer(const JsonBuffer &) = delete;
        JsonBuffer(JsonBuffer &&)      = delete;

        Iterator begin() const;
        Iterator end() const;
        size_type size() const;
        pointer data() const;
        std::string to_string() const;
    };





    /************************************************************
     * @brief "An iterator class for traversing the JSON data
     *  contained within a `JT::JsonBuffer`. The iterator is a
     *  random access iterator that provides function members for
     *  dereferencing, pointer access, incrementing, decrementing,
     *  and comparing iterators."
     ************************************************************/
    class JsonBuffer::Iterator
    {
      public:
        // Iterator Traits
        using iterator_category = std::random_access_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        // Class Traits
        using value_type = char;
        using size_type  = std::size_t;
        using pointer    = const char *;
        using reference  = const char &;


      private:
        const char *range_begin;
        const char *range_end;
        const char *iter;


      public:
        explicit Iterator(pointer begin, pointer end, pointer current)
          : range_begin(begin),
            range_end(end),
            iter(current) {}


        inline Iterator begin() const {
            return Iterator(range_begin,
              range_end,
              const_cast<pointer>(range_begin));
        }


        inline Iterator end() const {
            return Iterator(range_begin,
              range_end,
              const_cast<pointer>(range_end));
        }


        inline char operator[](difference_type n) const { return *(iter + n); }


        inline char at(difference_type n) const {
            if (iter + n >= range_end || iter + n < range_begin) {
                throw std::out_of_range(
                  "Iterator out of range.\nCULPRIT: JsonInterpreter::Iterator::at");
            }

            return *(iter + n);
        }


        inline char operator&() const { return *iter; }
        inline pointer operator->() const { return iter; }
        inline reference operator*() const { return *iter; }


        inline Iterator &operator++() {
            ++iter;
            return *this;
        }


        inline Iterator operator++(int) {
            Iterator tmp = *this;
            ++iter;
            return tmp;
        }


        inline Iterator &operator--() {
            --iter;
            return *this;
        }


        inline Iterator operator--(int) {
            Iterator tmp = *this;
            --iter;
            return tmp;
        }


        inline Iterator operator+(difference_type n) const {
            return Iterator(range_begin,
              range_end,
              iter + n);
        }


        friend inline Iterator operator+(difference_type n, const Iterator &it) {
            return Iterator(it.range_begin,
              it.range_end,
              it.iter + n);
        }


        inline Iterator &operator+=(difference_type n) {
            iter += n;
            return *this;
        }


        inline Iterator operator-(difference_type n) const {
            return Iterator(range_begin,
              range_end,
              iter - n);
        }


        inline difference_type operator-(const Iterator &other) const {
            return iter - other.iter;
        }


        inline Iterator &operator-=(difference_type n) {
            iter -= n;
            return *this;
        }


        inline bool operator==(const Iterator &other) const { return iter == other.iter; }
        inline bool operator!=(const Iterator &other) const { return iter != other.iter; }
        inline bool operator<(const Iterator &other) const { return iter < other.iter; }
        inline bool operator>(const Iterator &other) const { return iter > other.iter; }
        inline bool operator<=(const Iterator &other) const { return iter <= other.iter; }
        inline bool operator>=(const Iterator &other) const { return iter >= other.iter; }
    };
} // namespace JT
