#pragma once
#include <string>
#include <vector>

std::vector<std::string> split(std::string const& line,
                               std::string const& delimeter);
std::string BoolArrayToString(bool const arr[], int length);
void AssignIntToBoolArray(bool arr[], int length, int number);
std::vector<std::string> FindAllTxtFiles();
std::vector<std::string> ReadFileContents(std::string const filePath);