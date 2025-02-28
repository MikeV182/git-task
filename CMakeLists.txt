cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

include_directories(${PROJECT_SOURCE_DIR}/include)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} main.cpp src/candle.cpp)

target_link_libraries(${PROJECT_NAME} gtest gtest_main)
