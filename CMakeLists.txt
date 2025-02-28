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

enable_testing()

add_test(NAME CandleTest_BodyContains_GreenCandle_InsideBody COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.BodyContains_GreenCandle_InsideBody)
add_test(NAME CandleTest_BodyContains_GreenCandle_OutsideBody COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.BodyContains_GreenCandle_OutsideBody)
add_test(NAME CandleTest_BodyContains_RedCandle_InsideBody COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.BodyContains_RedCandle_InsideBody)
add_test(NAME CandleTest_Contains_PriceInsideRange COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.Contains_PriceInsideRange)
add_test(NAME CandleTest_Contains_PriceAtLow COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.Contains_PriceAtLow)
add_test(NAME CandleTest_Contains_PriceAtHigh COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.Contains_PriceAtHigh)
add_test(NAME CandleTest_FullSize_Normal COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.FullSize_Normal)
add_test(NAME CandleTest_FullSize_Zero COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.FullSize_Zero)
add_test(NAME CandleTest_FullSize_NegativeRange COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.FullSize_NegativeRange)
add_test(NAME CandleTest_BodySize_GreenCandle COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.BodySize_GreenCandle)
add_test(NAME CandleTest_BodySize_RedCandle COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.BodySize_RedCandle)
add_test(NAME CandleTest_BodySize_Zero COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.BodySize_Zero)
add_test(NAME CandleTest_IsRed_RedCandle COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.IsRed_RedCandle)
add_test(NAME CandleTest_IsRed_GreenCandle COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.IsRed_GreenCandle)
add_test(NAME CandleTest_IsRed_ZeroSize COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.IsRed_ZeroSize)
add_test(NAME CandleTest_IsGreen_GreenCandle COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.IsGreen_GreenCandle)
add_test(NAME CandleTest_IsGreen_RedCandle COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.IsGreen_RedCandle)
add_test(NAME CandleTest_IsGreen_ZeroSize COMMAND ${PROJECT_NAME} --gtest_filter=CandleTest.IsGreen_ZeroSize)
