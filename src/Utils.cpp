#include "Utils.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string Utils::Trim(std::string const& str, std::string const& trimmable,
                        Utils::TrimSettings settings) {
    bool left = settings == Utils::TrimSettings::TrimBothEnds;
    bool right = left;
    left |= settings == Utils::TrimSettings::TrimLeft;
    right |= settings == Utils::TrimSettings::TrimRight;

    auto is_trimmable = [&](char c) {
        return trimmable.find(c) != std::string::npos;
    };

    auto left_it = left ? std::find_if_not(str.begin(), str.end(), is_trimmable)
                        : str.begin();
    auto right_it =
        right ? std::find_if_not(str.rbegin(), str.rend(), is_trimmable).base()
              : str.rbegin().base();

    return std::string(left_it, right_it);
}

bool Utils::IsPositiveNumber(std::string const& s) {
    return s.size() && std::find_if_not(s.begin(), s.end(), [](char c) {
                           return isdigit(c);
                       }) == s.end();
}

std::vector<std::string> Utils::Split(std::string const& line,
                                      std::string const& delimiter) {
    std::vector<std::string> parts = {};

    std::size_t pos = line.find(delimiter);
    std::size_t start = 0;

    while (pos != std::string::npos) {
        auto const part = line.substr(start, pos - start);
        if (!part.empty()) {
            parts.push_back(part);
        }

        start = pos + delimiter.length();
        pos = line.find(delimiter, start);
    }

    auto const part = line.substr(start);
    if (!part.empty()) {
        parts.push_back(part);
    }

    return parts;
}

std::vector<std::string> Utils::Split(std::string const& line,
                                      std::vector<char> const& delimiters) {
    std::vector<std::string> parts = {};
    std::string const delimiter(delimiters.begin(), delimiters.end());

    std::size_t pos = line.find_first_of(delimiter);
    std::size_t start = 0;

    while (pos != std::string::npos) {
        auto const part = line.substr(start, pos - start);
        if (!part.empty()) {
            parts.push_back(part);
        }

        start = pos + 1;
        pos = line.find_first_of(delimiter, start);
    }

    auto const part = line.substr(start);
    if (!part.empty()) {
        parts.push_back(part);
    }

    return parts;
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