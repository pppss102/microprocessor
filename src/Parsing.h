#ifndef __PARSING_H
#define __PARSING_H

#include <cstdint>
#include <exception>
#include <string>
#include <variant>
#include <vector>

namespace Parsing {
enum class Operation {
    Read,
    Next,
    Mov,
    Reset,
    Ls,
    Add,
    Not,
    Xor,
    MuxIn,
    Inc,
    Dec,
    Ll1,
    Lr1,
    Al1,
    Ar1,
    Cl1,
    Cr1,
};
enum class Operand {
    RegisterA,
    RegisterB,
    RegisterC,
    RegisterD,
    RegisterE,
    RegisterF,
    Counter,
    Rom,
    Flag,
};

struct CommandEntry {
    Operation operation;
    std::vector<std::variant<Operand, uint8_t>> operands;
};

using Command = std::vector<CommandEntry>;

std::pair<uint8_t, Command> ParseCommandString(std::string const& str);

} // namespace Parsing

#endif