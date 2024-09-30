#pragma once
#include <cstdint>
#include <functional>
#include <string>
#include <vector>

namespace Utils {
enum class TrimSettings {
    TrimLeft,
    TrimRight,
    TrimBothEnds,
};

std::string Trim(std::string const& str, std::string const& trimmable,
                 TrimSettings settings);

bool IsPositiveNumber(std::string const& s);

std::vector<std::string> Split(std::string const& line,
                               std::string const& delimiter,
                               bool add_empty = false);

std::vector<std::string> Split(std::string const& line,
                               std::vector<char> const& delimiters,
                               bool add_empty = false);

std::vector<std::string> ReadFileContents(std::string const filePath);

uint8_t ReverseBits(uint8_t x, int width);
} // namespace Utils