#pragma once

#include "ForcedLineStatement.h"
#include "Modules.h"
#include "Processor.h"
#include "Utils.h"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class ProcessorLanguageInterpreter {
    bool processorType{};
    std::vector<ForcedLineStatement> lines;

  public:
    ProcessorLanguageInterpreter() {}
    void AddLine(std::string const& line, Modules::Processor type) {
        ForcedLineStatement newLine(line, type);
        lines.push_back(newLine);
    }
    void PrintToConsole() {
        for (ForcedLineStatement const& line : lines) {
            std::cout << line.ToString() << '\n';
        }
    }
    void CompileCode(std::string const& codePath_s) {
        std::vector<std::string> code = Utils::ReadFileContents(codePath_s);
        Modules::Processor processorType{};
        if (code[0] == "F") {
            processorType = Modules::Processor::Forced;
        } else {
            processorType = Modules::Processor::Natural;
        }
        for (int i = 1; i < code.size(); i++) {
            std::cout << code[i] << '\n';
            AddLine(code[i], processorType);
        }
        std::filesystem::path codePath(codePath_s);
        std::ofstream outputPath("Rezult/Compiled_" + code[0] + "_" +
                                 codePath.filename().string());
        for (ForcedLineStatement const& line : lines) {
            outputPath << line.ToString() << '\n';
        }
        outputPath.close();
    }
};
