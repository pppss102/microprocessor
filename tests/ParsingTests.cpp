#include "../src/Parsing.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

extern std::vector<std::vector<std::string>>
GetQueries(std::vector<std::string> const& operations);

extern std::variant<Parsing::Operand, uint8_t>
GetOperand(std::string const& str);

TEST(Parsing_GetQueries, simple) {
    std::vector<std::string> operations = {
        "next 10",
        "reset a, b, c, d",
    };

    auto queries = GetQueries(operations);

    EXPECT_THAT(queries[0], ::testing::ElementsAre("next", "10"));
    EXPECT_THAT(queries[1],
                ::testing::ElementsAre("reset", "a", "b", "c", "d"));
}

TEST(Parsing_GetOperand, test_support) {
    std::vector<std::string> ops = {"a", "b",   "c",   "d",   "e",
                                    "f", "cnt", "rom", "flag"};
    for (auto& op : ops) {
        EXPECT_NO_THROW(GetOperand(op));
    }

    EXPECT_THROW(GetOperand("lll"), std::logic_error);
}

TEST(Parsing_GetOperand, numbers) {
    for (int i = 0; i < 256; i++) {
        EXPECT_NO_THROW(GetOperand(std::to_string(i)));
    }

    EXPECT_THROW(GetOperand("256"), std::logic_error);
    EXPECT_THROW(GetOperand("-256"), std::logic_error);
}