#include <gtest/gtest.h>
#include "candle.h"

TEST(CandleTest, BodyContains_GreenCandle_InsideBody)
{
    Candle candle(10.0, 15.0, 8.0, 12.0);    // зеленая свеча, открытие 10, закрытие 12
    EXPECT_TRUE(candle.body_contains(11.0)); // Цена внутри тела
}

TEST(CandleTest, BodyContains_GreenCandle_OutsideBody)
{
    Candle candle(10.0, 15.0, 8.0, 12.0);    // зеленая свеча, открытие 10, закрытие 12
    EXPECT_FALSE(candle.body_contains(9.5)); // Цена за пределами тела
}

TEST(CandleTest, BodyContains_RedCandle_InsideBody)
{
    Candle candle(12.0, 15.0, 8.0, 10.0);    // красная свеча, открытие 12, закрытие 10
    EXPECT_TRUE(candle.body_contains(11.0)); // Цена внутри тела
}
