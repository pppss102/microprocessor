#pragma once

namespace Modules {
enum class Processor { Forced, Natural };
enum class Register { S_Data, LL1, LR1, AL1, AR1, CL1, CR1 };
enum class MUX { Din, RegA, RegB, RegC, RegD, RegE, RegF };
enum class ALU { LpR, NotL, NotR, Lp1, Lm1, Rp1, Rm1, LxorR };
enum class RST { RegA, RegB, RegC, RegD, RegE, RegF, CNT, ROM, Flag };
enum class Flag {
    F_NULL,
    AH,
    AL,
    BH,
    BL,
    CH,
    CL,
    DH,
    DL,
    EH,
    EL,
    FH,
    FL,
    CNT,
    ALU,
    FALSE
};
} // namespace Modules