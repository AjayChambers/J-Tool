#===========================================================
# TARGET LIBRARY: 'json_file'
#===========================================================
add_library(json_file json-file.cxx)
target_link_libraries(json_file PRIVATE json_buffer)
set_target_properties(json_file PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${JT_LIB_DIR}
  LIBRARY_OUTPUT_DIRECTORY ${JT_LIB_DIR})
