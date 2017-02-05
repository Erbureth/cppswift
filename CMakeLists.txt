cmake_minimum_required(VERSION 2.6)
project(cppswift)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(test/GTest.cmake)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Poco REQUIRED Foundation Net)

set(Poco_All_LIBRARY ${Poco_Net_LIBRARY} ${Poco_Foundation_LIBRARY})

add_subdirectory(src)
add_subdirectory(test)

add_library(cppswift SHARED ${CPPSWIFT_FILES})
target_link_libraries(cppswift ${Poco_All_LIBRARY})
set_target_properties(cppswift PROPERTIES SOVERSION 0.1.0 VERSION 0)

add_library(cppswift-static STATIC ${CPPSWIFT_FILES})
target_link_libraries(cppswift-static ${Poco_All_LIBRARY})

install(TARGETS cppswift cppswift-static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(DIRECTORY src/ DESTINATION include/cppswift FILES_MATCHING PATTERN "*.h")

enable_testing()

add_executable(cppswift_test ${CPPSWIFT_TEST_FILES} ${CPPSWIFT_FILES})
target_link_libraries(cppswift_test ${GTEST_BOTH_LIBRARIES} ${Poco_All_LIBRARY})

foreach(CPPSWIFT_TEST_FILE ${CPPSWIFT_TEST_FILES})
    message(STATUS "Adding tests from " ${CPPSWIFT_TEST_FILE})
    GTEST_ADD_TESTS(cppswift_test "" ${CPPSWIFT_TEST_FILE})
endforeach()
