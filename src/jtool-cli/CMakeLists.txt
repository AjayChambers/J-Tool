
#===========================================================
# J-TOOL COMMAND-LINE INTERFACE
#===========================================================
add_executable(jtool "main.cxx")

target_link_libraries(jtool PRIVATE
  json_file
  json_buffer
  json_analyzer)

set_target_properties(jtool
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${RUNTIME_DIR_}
    OUTPUT_NAME "jtool")
