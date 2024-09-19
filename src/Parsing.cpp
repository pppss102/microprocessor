#include "Parsing.h"
#include "FlatMap.h"
#include <stdexcept>

using namespace Parsing;

#pragma region Lookup Tables

FlatMap<ParsingResult, std::string> const exceptionStr({
    {ParsingResult::Ok, "Ok"},
    {ParsingResult::MultipleColons, "Multiple colons in a single line"},
    {ParsingResult::IncorrectLabel,
     "Incorrect label (must be an integer in the range 0-255)"},
});

#pragma endregion

char const* ParsingException::what() const noexcept {
    auto const resultStr = exceptionStr.Find(result);
    std::string const explain =
        resultStr.has_value() ? *resultStr : "Unknown error";

    return ("Exception occurred during parsing: " + explain).c_str();
}

std::pair<uint16_t, Command>
Parsing::ParseCommandString(std::string const& str) {
    throw std::logic_error("Not implemented");
}