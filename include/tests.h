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

TEST(CandleTest, Contains_PriceInsideRange)
{
    Candle candle(10.0, 15.0, 8.0, 12.0);
    EXPECT_TRUE(candle.contains(11.0)); // Цена внутри диапазона
}

TEST(CandleTest, Contains_PriceAtLow)
{
    Candle candle(10.0, 15.0, 8.0, 12.0);
    EXPECT_TRUE(candle.contains(8.0)); // Цена на низу диапазона
}

TEST(CandleTest, Contains_PriceAtHigh)
{
    Candle candle(10.0, 15.0, 8.0, 12.0);
    EXPECT_TRUE(candle.contains(15.0)); // Цена на верху диапазона
}

TEST(CandleTest, FullSize_Normal)
{
    Candle candle(10.0, 15.0, 8.0, 12.0);
    EXPECT_DOUBLE_EQ(candle.full_size(), 7.0); // Размер свечи от 8 до 15
}

TEST(CandleTest, FullSize_Zero)
{
    Candle candle(10.0, 10.0, 10.0, 10.0);
    EXPECT_DOUBLE_EQ(candle.full_size(), 0.0); // Свеча без размаха
}

TEST(CandleTest, FullSize_NegativeRange)
{
    Candle candle(12.0, 15.0, 8.0, 10.0);
    EXPECT_DOUBLE_EQ(candle.full_size(), 7.0); // Диапазон от 8 до 15
}

TEST(CandleTest, BodySize_GreenCandle)
{
    Candle candle(10.0, 15.0, 8.0, 12.0);
    EXPECT_DOUBLE_EQ(candle.body_size(), 2.0); // Разница между open (10) и close (12)
}

TEST(CandleTest, BodySize_RedCandle)
{
    Candle candle(12.0, 15.0, 8.0, 10.0);
    EXPECT_DOUBLE_EQ(candle.body_size(), 2.0); // Разница между open (12) и close (10)
}

TEST(CandleTest, BodySize_Zero)
{
    Candle candle(10.0, 15.0, 8.0, 10.0);
    EXPECT_DOUBLE_EQ(candle.body_size(), 0.0); // Свеча без тела (open == close)
}
