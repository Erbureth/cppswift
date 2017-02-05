cmake_minimum_required(VERSION 2.6)
project(cppswift)

include(test/GTest.cmake)

add_subdirectory(src)
add_subdirectory(test)

add_library(cppswift ${CPPSWIFT_FILES})
set_target_properties(cppswift PROPERTIES SOVERSION 0.1.0 VERSION 0)

add_library(cppswift-static STATIC ${CPPSWIFT_FILES})

install(TARGETS cppswift cppswift-static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(DIRECTORY src/ DESTINATION include/cppswift FILES_MATCHING PATTERN "*.h")

enable_testing()

add_executable(cppswift_test ${CPPSWIFT_TEST_FILES} ${CPPSWIFT_FILES})
target_link_libraries(cppswift_test ${GTEST_BOTH_LIBRARIES})

foreach(CPPSWIFT_TEST_FILE ${CPPSWIFT_TEST_FILES})
    message(STATUS "Adding tests from " ${CPPSWIFT_TEST_FILE})
    GTEST_ADD_TESTS(cppswift_test "" ${CPPSWIFT_TEST_FILE})
endforeach()
