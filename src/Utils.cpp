#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string const& line,
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

std::string BoolArrayToString(bool const arr[], int length) {
    std::string result = "";
    for (int i = 0; i < length; i++) {
        result += std::to_string(arr[i]);
    }
    return result;
}

void AssignIntToBoolArray(bool arr[], int length, int number) {
    for (int i = length - 1; i >= 0; i--) {
        arr[i] = number % 2;
        number /= 2;
    }
}

std::vector<std::string> FindAllTxtFiles() {
    using namespace std::filesystem;
    path CompilePath = current_path() /= "Code";
    std::vector<std::string> txtPaths(0);
    for (auto const& txtPath : directory_iterator(CompilePath)) {
        if (txtPath.is_regular_file() && txtPath.path().extension() == ".txt") {
            txtPaths.push_back(txtPath.path().string());
        }
    }
    return txtPaths;
}

std::vector<std::string> ReadFileContents(std::string const filePath) {
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