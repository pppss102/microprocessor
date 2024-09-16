#include "Utils.h"
#include <iostream>
#include <string>
#include <vector>

void SplitTemplate(std::string input, std::string delimeter,
                   std::string expected) {
    std::vector<std::string> rezultVector = split(input, delimeter);
    std::string rezult = rezultVector[0] + rezultVector[1] + rezultVector[2];

    if (expected != rezult) {
        std::cout << "TEST FAILED\n";
        std::cout << "Input: \"" << input << "\" expected: \"" << expected
                  << "\" rezult \"" << rezult << "\"\n";
    }
}

void BoolArrayToStringTest(bool input[], int length, std::string expected) {
    std::string rezult = BoolArrayToString(input, length);

    if (expected != rezult) {
        std::cout << "TEST FAILED\n";
        std::cout << "expected: \"" << expected << "\" rezult \"" << rezult
                  << "\"\n";
    }
}

void Testing() {
    SplitTemplate("1,2,3", ",", "123");
    SplitTemplate("1, 2, 3", ", ", "123");
    bool test[8] = {0, 1, 1, 1, 0, 1, 0, 0};
    BoolArrayToStringTest(test, 8, "01110100");
}