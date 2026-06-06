########################################
# JSON Buffer Library
########################################
add_library(json_buffer "json-buffer.cxx")
set_target_properties(json_buffer
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${ARCHIVE_DIR_}
    LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_DIR_})