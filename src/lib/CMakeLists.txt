#===========================================================
# TARGET LIBRARY: '"json_buffer"'
#===========================================================
add_library(json_buffer json-buffer.cxx)
set_target_properties(json_buffer PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${JT_LIB_DIR}
  LIBRARY_OUTPUT_DIRECTORY ${JT_LIB_DIR})






#===========================================================
# TARGET LIBRARY: 'json_file'
#===========================================================
add_library(json_file json-file.cxx)
target_link_libraries(json_file PRIVATE json_buffer)
set_target_properties(json_file PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${JT_LIB_DIR}
  LIBRARY_OUTPUT_DIRECTORY ${JT_LIB_DIR})






#===========================================================
# TARGET LIBRARY: 'json_analyzer'
#===========================================================
add_library(json_analyzer json-analyzer.cxx)
target_link_libraries(json_analyzer PRIVATE json_buffer json_file)
set_target_properties(json_analyzer PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${JT_LIB_DIR}
  LIBRARY_OUTPUT_DIRECTORY ${JT_LIB_DIR})
