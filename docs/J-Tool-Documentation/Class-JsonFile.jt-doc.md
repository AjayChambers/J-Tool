# Class: JsonFile

JsonFile is used to create an abstraction of a JSON file that exist on a system. JsonFile requires
a path as an argument when it is being constructed. The `std::FileSystem::path` is immutable and
cannot be changed later, consequently, the path one sets for a JsonFile instance is the path to the
file that the JsonFile instance represents. And that is what I mean when I say _"abstraction of a
JSON file"_.

## Public Member Functions

1. ### `ResultFile JsonFile::read()`

    **Returns:** `ResultFile` = `std::variant<int, std::string>` \
    A string is