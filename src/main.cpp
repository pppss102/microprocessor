#include <iostream>
#include <string>
#include <vector>
#include "Tests.h"
#include "Processor.h"
#include "ForcedLineStatement.h"
#include "Utils.h"

int main()
{
    std::vector<std::string> txtFiles = FindAllTxtFiles();
    for (const std::string &filePath : txtFiles)
    {
        ProcessorLanguageInterpreter compiler;
        compiler.CompileCode(filePath);
    }

    std::cout << "Done: ";
    std::string ending;
    std::cin >> ending;

    return 0;
}
