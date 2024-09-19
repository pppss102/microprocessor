#include "Parsing.h"
#include "FlatMap.h"
#include "Utils.h"
#include <stdexcept>

using namespace Parsing;

#pragma region Lookup Tables
#pragma endregion

char const* ParsingException::what() const noexcept {
    return ("Exception occurred during parsing: " + explain).c_str();
}

std::pair<uint8_t, Command>
Parsing::ParseCommandString(std::string const& str) {
    auto labeled_command = Utils::Split(str, ":");

    if (labeled_command.size() != 2) {
        throw ParsingException("Multiple label declarations in a single row");
    }
    if (!Utils::IsPositiveNumber(labeled_command[0])) {
        throw ParsingException(
            "Label is incorrect (should be an integer in the range 0-255)");
    }

    int rawIndex = std::stoi(labeled_command[0]);
    if (rawIndex > 255) {
        throw ParsingException(
            "Label is incorrect (should be an integer in the range 0-255)");
    }

    uint8_t index = rawIndex;

    auto operations = Utils::Split(labeled_command[1], "&&");
}