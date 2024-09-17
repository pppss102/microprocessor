#include "Utils.h"
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout
            << "Usage: Compiler.exe {input text file} {output directory}\n";
        return 0;
    }

    ProcessorLanguageInterpreter interpreter;
    interpreter.CompileCode(argv[1], argv[2]);

    return 0;
}
