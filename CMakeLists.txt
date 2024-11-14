cmake_minimum_required(VERSION 3.14)
project(c-plus-plus-data-structures)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
  DOWNLOAD_EXTRACT_TIMESTAMP true
)

FetchContent_MakeAvailable(googletest)

include_directories(./)

file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")

foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME}_test ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME}_test gtest_main)
endforeach()

include(GoogleTest)
foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    gtest_discover_tests(${TEST_NAME}_test)
endforeach()
