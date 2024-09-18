#include "ForcedCommand.h"
#include "../Utils.h"
#include <sstream>

ForcedCommand::Command::Command() {
    mux = 0;
    reg = {};
    alu = 0;
    reset = 0;
    data_out = 0;
    decrement_cnt = 0;
    flag = 0;
    index = 0;
    next = 0;
}

std::bitset<80> ForcedCommand::Command::toBitset() {
    std::bitset<80> output;

    output |= Utils::ReverseBits(next, 8);
    output <<= 4;

    output |= Utils::ReverseBits(flag, 4);
    output <<= 1;

    output |= decrement_cnt;
    output <<= 1;

    output |= data_out;
    output <<= 9;

    output |= reset;
    output <<= 8;

    output |= alu;
    output <<= 7;

    for (int i = reg.size() - 1; i >= 0; i--) {
        output |= reg[i];
        output <<= 7;
    }

    output |= mux;

    return output;
}

std::string ForcedCommand::Command::toString() {
    std::stringstream str;
    std::string s = toBitset().to_string();
    std::reverse(s.begin(), s.end());
    str << (int)index << " => \"" << s << "\", -- " << comment;

    return str.str();
}