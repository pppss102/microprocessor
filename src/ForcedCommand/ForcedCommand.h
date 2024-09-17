#include <array>
#include <bitset>
#include <cstdint>
#include <string>
#ifndef _FORCED_COMMAND_H
#define _FORCED_COMMAND_H

namespace ForcedCommand {

enum mux_cmd {
    MUX_NONE = 0,
    MUX_DIN = 1,
    MUX_REG_A = 1 << 1,
    MUX_REG_B = 1 << 2,
    MUX_REG_C = 1 << 3,
    MUX_REG_D = 1 << 4,
    MUX_REG_E = 1 << 5,
    MUX_REG_F = 1 << 6,
};

enum reg_cmd {
    REG_IN = 1, // arba is mux'o arba is ALU (M output'o)
    REG_LL1 = 1 << 1,
    REG_LR1 = 1 << 2,
    REG_AL1 = 1 << 3,
    REG_AR1 = 1 << 4,
    REG_CL1 = 1 << 5,
    REG_CR1 = 1 << 6,
};

enum alu_cmd {
    ALU_SUM = 1,
    ALU_INVERT_L = 1 << 1,
    ALU_INVERT_R = 1 << 2,
    ALU_INC_L = 1 << 3,
    ALU_DEC_L = 1 << 4,
    ALU_INC_R = 1 << 5,
    ALU_DEC_R = 1 << 6,
    ALU_XOR = 1 << 7
};

enum reset_cmd {
    RESET_A = 1,
    RESET_B = 1 << 1,
    RESET_C = 1 << 2,
    RESET_D = 1 << 3,
    RESET_E = 1 << 4,
    RESET_F = 1 << 5,
    RESET_CNT = 1 << 6,
    RESET_ROM = 1 << 7,
    RESET_FLAG = 1 << 8,
};

enum flag_cmd {
    FLAG_EMPTY,
    FLAG_A_HIGH,
    FLAG_A_LOW,
    FLAG_B_HIGH,
    FLAG_B_LOW,
    FLAG_C_HIGH,
    FLAG_C_LOW,
    FLAG_D_HIGH,
    FLAG_D_LOW,
    FLAG_E_HIGH,
    FLAG_E_LOW,
    FLAG_F_HIGH,
    FLAG_F_LOW,
    FLAG_CNT_ZERO,
    FLAG_ALU_OVERFLOW,
    // kazkodel yra dar flagu laboro lenteleje bet manrods jie nepasiekiami
};

struct Command {
    uint8_t mux;
    std::array<uint8_t, 6> reg;
    uint8_t alu;
    uint16_t reset;
    bool data_out;
    bool decrement_cnt;
    uint8_t flag;
    uint8_t index;
    uint8_t next;
    std::string comment;

    Command();
    std::bitset<80> toBitset();
    std::string toString();
};

} // namespace ForcedCommand

#endif