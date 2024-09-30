#include "Preprocessor.h"
#include "Utils.h"

std::string Preprocessor::RemoveComments(std::string const& str) {
    std::string const trimmed =
        Utils::Trim(str, " \t", Utils::TrimSettings::TrimBothEnds);
    auto const parts = Utils::Split(trimmed, ";", true);

    if (parts[0].empty() || trimmed[0] == ';') {
        return "";
    }

    return parts[0];
}
