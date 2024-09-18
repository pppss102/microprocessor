#include "../src/Utils.h"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(StringSplitTest, split) {
    auto result = Utils::Split("1,2,3,", ",");
    EXPECT_EQ(result[0] + result[1] + result[2], "123");
}
