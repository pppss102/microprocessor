#include "Utils.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string Utils::Trim(std::string const& str,
                        std::function<bool(char)> const& trimmable,
                        Utils::TrimSettings settings) {
    bool left = settings == Utils::TrimSettings::TrimBothEnds;
    bool right = left;
    left |= settings == Utils::TrimSettings::TrimLeft;
    right |= settings == Utils::TrimSettings::TrimRight;

    auto left_it = left ? std::find_if_not(str.begin(), str.end(), trimmable)
                        : str.begin();
    auto right_it =
        right ? std::find_if_not(str.rbegin(), str.rend(), trimmable).base()
              : str.rbegin().base();

    return std::string(left_it, right_it);
}

bool Utils::IsPositiveNumber(std::string const& s) {
    return s.size() && std::find_if_not(s.begin(), s.end(), [](char c) {
                           return isdigit(c);
                       }) == s.end();
}

std::vector<std::string> Utils::Split(std::string const& line,
                                      std::string const& delimeter) {
    std::vector<std::string> parts = {};

    std::size_t pos = line.find(delimeter);
    std::size_t start = 0;

    while (pos != std::string::npos) {
        parts.push_back(line.substr(start, pos - start));
        start = pos + delimeter.length();
        pos = line.find(delimeter, pos + 1);
    }

    parts.push_back(line.substr(start));

    return parts;
}

std::string Utils::BoolArrayToString(bool const arr[], int length) {
    std::string result = "";
    for (int i = 0; i < length; i++) {
        result += std::to_string(arr[i]);
    }
    return result;
}

void Utils::AssignIntToBoolArray(bool arr[], int length, int number) {
    for (int i = length - 1; i >= 0; i--) {
        arr[i] = number % 2;
        number /= 2;
    }
}

std::vector<std::string> Utils::ReadFileContents(std::string const filePath) {
    std::vector<std::string> contents(0);
    std::ifstream fileInput(filePath);
    while (fileInput) {
        std::string line;
        std::getline(fileInput, line);
        contents.push_back(line);
    }
    fileInput.close();
    contents.pop_back();
    return contents;
}

uint8_t Utils::ReverseBits(uint8_t x, int width) {
    uint8_t out = 0;

    for (int i = 0; i < width; i++) {
        out <<= 1;
        if (x & 1) {
            out ^= 1;
        }

        x >>= 1;
    }

    return out;
}