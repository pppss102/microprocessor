#include "Parsing.h"
#include "FlatMap.h"
#include "Utils.h"
#include <stdexcept>

using namespace Parsing;

#pragma region Lookup Tables
FlatMap<std::string, Operation> const str_operation({{
    {"read", Operation::Read},
    {"next", Operation::Next},
    {"mov", Operation::Mov},
    {"reset", Operation::Reset},
    {"ls", Operation::Ls},
    {"add", Operation::Add},
    {"not", Operation::Not},
    {"xor", Operation::Xor},
    {"mux", Operation::MuxIn},
    {"inc", Operation::Inc},
    {"dec", Operation::Dec},
    {"ll1", Operation::Ll1},
    {"lr1", Operation::Lr1},
    {"al1", Operation::Al1},
    {"ar1", Operation::Ar1},
    {"cl1", Operation::Cl1},
    {"cr1", Operation::Cr1},
}});

FlatMap<std::string, Operand> const str_operand({
    {"a", Operand::RegisterA},
    {"b", Operand::RegisterB},
    {"c", Operand::RegisterC},
    {"d", Operand::RegisterD},
    {"e", Operand::RegisterE},
    {"f", Operand::RegisterF},
    {"cnt", Operand::Counter},
    {"rom", Operand::Rom},
    {"flag", Operand::Flag},
});
#pragma endregion

std::vector<std::vector<std::string>>
GetQueries(std::vector<std::string> const& operations) {
    std::vector<std::vector<std::string>> queries(operations.size());
    for (int i = 0; auto& query : queries) {
        query = Utils::Split(operations[i], std::vector{' ', ',', '\t'});
        for (auto& part : query) {
            part = Utils::Trim(part, " ,\t", Utils::TrimSettings::TrimBothEnds);
        }
        i++;
    }

    return queries;
}

std::variant<Operand, uint8_t> GetOperand(std::string const& str) {
    if (Utils::IsPositiveNumber(str)) {
        int value = std::stoi(str);
        if (value < 1 || value > 15) {
            throw std::logic_error("Integers for flag checking should "
                                   "be in the range 1-15");
        }

        return static_cast<uint8_t>(value);
    }
    auto value = str_operand.Find(str);
    if (!value.has_value()) {
        throw std::logic_error("Unknown operand " + str);
    }

    return *value;
}

std::pair<uint8_t, Command>
Parsing::ParseCommandString(std::string const& str) {
    auto labeled_command = Utils::Split(str, ":");

    if (labeled_command.size() != 2) {
        throw std::runtime_error("Multiple label declarations in a single row");
    }
    if (!Utils::IsPositiveNumber(labeled_command[0])) {
        throw std::out_of_range(
            "Label is incorrect (should be an integer in the range 0-255)");
    }

    int rawIndex = std::stoi(labeled_command[0]);
    if (rawIndex > 255) {
        throw std::out_of_range(
            "Label is incorrect (should be an integer in the range 0-255)");
    }
    uint8_t index = rawIndex;

    auto operations = Utils::Split(labeled_command[1], "&&");
    std::vector<std::vector<std::string>> queries = GetQueries(operations);

    Command command(operations.size());
    for (int i = 0; auto& operation : command) {
        auto op = str_operation.Find(queries[i][0]);
        if (!op.has_value()) {
            throw std::logic_error("Incorrect operation " + queries[i][0]);
        }

        operation.operation = *op;

        for (int j = 1; j < queries[i].size(); j++) {
            operation.operands.push_back(GetOperand(queries[i][j]));
        }
        i++;
    }

    return {index, command};
}