#pragma once
#include <string>
#include <vector>

namespace Utils {
std::vector<std::string> split(std::string const& line,
                               std::string const& delimeter);
std::string BoolArrayToString(bool const arr[], int length);
void AssignIntToBoolArray(bool arr[], int length, int number);
std::vector<std::string> ReadFileContents(std::string const filePath);
uint8_t ReverseBits(uint8_t x, int width);
} // namespace Utils