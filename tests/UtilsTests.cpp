#include "../src/Utils.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(Utils_Split, single_delimiter_split) {
    auto result = Utils::Split("1,2,3,", ",");
    EXPECT_THAT(result, ::testing::ElementsAre("1", "2", "3"));
}

TEST(Utils_Split, long_delimiter_split) {
    auto result = Utils::Split("1,,2,,3,,,,", ",,");
    EXPECT_THAT(result, ::testing::ElementsAre("1", "2", "3"));
}
