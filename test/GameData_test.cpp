#include <gtest/gtest.h>
#include "GameData.hpp"

TEST(GameDataTest, testGameDataRead) {
    int value = GameData::read<int>("materials/soils", "brown.fertility");
    ASSERT_EQ(70, value);
}