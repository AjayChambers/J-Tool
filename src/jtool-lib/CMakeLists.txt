#===========================================================
# TARGET LIBRARY: 'json_analyzer'
#===========================================================
add_library(json_analyzer "json-analyzer.cxx")

target_link_libraries(json_analyzer
  PRIVATE
    json_buffer
    json_file)

set_target_properties(json_analyzer
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${ARCHIVE_DIR_}
    LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_DIR_})