cmake_minimum_required(VERSION 3.14)
project(GTestTests)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

set(COMMON_SRCS
    "../base/base.cpp"
)
add_executable(gtests gtest.cpp ${COMMON_SRCS})
target_include_directories(gtests PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(gtests PUBLIC gtest gtest_main)