set(DIRPATH_ ${CMAKE_CURRENT_SOURCE_DIR})

add_library(json-analyzer "${DIRPATH_}/analyzer.cpp")


    #===========================================================
# TARGET LIBRARY: 'json_analyzer'
#===========================================================
add_library(json_analyzer json-analyzer.cxx)
target_link_libraries(json_analyzer PRIVATE json_buffer json_file)
set_target_properties(json_analyzer PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${JT_LIB_DIR}
  LIBRARY_OUTPUT_DIRECTORY ${JT_LIB_DIR})

target_include_directories(json-analyzer PUBLIC
    "${DIRPATH_}/include"
    "${CMAKE_SOURCE_DIR}/include")