#include "ForcedLineStatement.h"
#include "Processor.h"
#include "Tests.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> txtFiles = FindAllTxtFiles();
    for (std::string const& filePath : txtFiles) {
        ProcessorLanguageInterpreter compiler;
        compiler.CompileCode(filePath);
    }

    std::cout << "Done: ";
    std::string ending;
    std::cin >> ending;

    return 0;
}
