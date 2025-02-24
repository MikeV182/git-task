cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} main.cpp src/candle.cpp)
