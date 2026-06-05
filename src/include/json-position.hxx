namespace JT
{
    struct JsonPosition {
        size_t line;
        size_t column;


        inline JsonPosition(size_t line = 1, size_t column = 1)
            : line(line),
              column(column) {}


        inline void advance(char c) {
            if (c == '\n') {
                line++;
                column = 1;
            } else {
                column++;
            }
        }
    };
} // namespace JT
