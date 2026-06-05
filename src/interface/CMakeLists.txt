add_subdirectory(lib)


#===========================================================
# Target Executable: 'jtool'
#===========================================================
add_executable(jtool "main.cxx")

target_include_directories(jtool PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/cli/include")

target_link_libraries(jtool PRIVATE
  json_file
  json_buffer
  json_analyzer)

set_target_properties(jtool PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${JT_BIN_DIR})
