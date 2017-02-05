find_package(Thread QUIET)
if(CMAKE_THREAD_LIBS_INIT)
    set(gtest_disable_pthreads OFF)
else()
    message(STATUS "Disabling pthread in Google Test")
    set(gtest_disable_pthreads ON)
endif()

include(ExternalProject)
ExternalProject_Add(googletest_project
    SOURCE_DIR /usr/src/googletest/googletest
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
               -DCMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}
               -Dgtest_disable_pthreads=${gtest_disable_pthreads}
    INSTALL_COMMAND "")

include(FindGTest)

ExternalProject_Get_Property(googletest_project binary_dir)
set(GTEST_LIBRARY_PATH ${binary_dir})

add_library(gtest STATIC IMPORTED)
set_property(TARGET gtest PROPERTY IMPORTED_LOCATION ${GTEST_LIBRARY_PATH}/libgtest.a)
add_dependencies(gtest googletest_project)

add_library(gtest_main STATIC IMPORTED)
set_property(TARGET gtest_main PROPERTY IMPORTED_LOCATION ${GTEST_LIBRARY_PATH}/libgtest_main.a)
add_dependencies(gtest googletest_project)

set(GTEST_LIBRARIES gtest)
set(GTEST_MAIN_LIBRARIES gtest_main)
set(GTEST_BOTH_LIBRARIES ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})

