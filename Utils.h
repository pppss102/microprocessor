#pragma once
#include <vector>
#include <string>

std::vector<std::string> split(const std::string &line, const std::string &delimeter);
std::string BoolArrayToString(const bool arr[], int length);
void AssignIntToBoolArray(bool arr[], int length, int number);