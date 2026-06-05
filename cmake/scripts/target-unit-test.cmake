include_guard(GLOBAL)
include("generate-test-id")

#################################################################
# FUNC: target_unit_test
# Description:
#   A helper function to create a unit test target in CMake.
# Parameters:
#   TEST_FILEPATH_ - The path to the test source file.
#   INC_DIR_LIST_ - A list of include directories for the test.
#   LIBRARY_LIST_ - A list of libraries to link against the test
#     executable.
#   RET_TEST_NAME_ - A variable to return the generated test
#     name.
#################################################################
function(target_unit_test TEST_FILEPATH_ INC_DIR_LIST_ LIBRARY_LIST_ RET_TEST_NAME_)
    # Validate that the test file exists
    if(NOT EXISTS ${TEST_FILEPATH_})
        message(FATAL_ERROR "Test file ${TEST_FILEPATH_} does not exist.")
    endif()

    # Add the executable to CMake targets
    add_executable("${TEST_NAME_}" "${TEST_FILEPATH_}")

    # Add the test to CTest for test discovery and execution
    add_test("${TEST_NAME_}" "${TEST_NAME_}")

    # Provide the test executable with the include directories it needs
    target_include_directories("${TEST_NAME_}"
      PUBLIC ${INC_DIR_LIST_})

    # Link the test executable with the provided libraries
    target_link_libraries("${TEST_NAME_}"
      PUBLIC ${LIBRARY_LIST_})
endfunction()