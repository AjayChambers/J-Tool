include_directories(
  ${SOURCE_DIR_}/interface/include
  ${SOURCE_DIR_}/json-analyzer/include
  ${SOURCE_DIR_}/json-buffer/include
  ${SOURCE_DIR_}/json-file/include
  ${SOURCE_DIR_}/include)

add_subdirectory("json-buffer")
add_subdirectory("json-file")
add_subdirectory("jtool-lib")
add_subdirectory("jtool-cli")
