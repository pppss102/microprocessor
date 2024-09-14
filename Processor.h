#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include "Modules.h"
#include "Processor.h"
#include "Utils.h"
#include "ForcedLineStatement.h"

class ProcessorLanguageInterpreter
{
	bool processorType{};
	std::vector<ForcedLineStatement> lines;

public:
	ProcessorLanguageInterpreter()
	{
	}
	void AddLine(const std::string &line)
	{
		ForcedLineStatement newLine(line);
		lines.push_back(newLine);
	}
	void PrintToConsole()
	{
		for (const ForcedLineStatement &line : lines)
		{
			std::cout << line.ToString() << '\n';
		}
	}
	void CompileCode(const std::string &codePath_s)
	{
		std::vector<std::string> code = ReadFileContents(codePath_s);
		for (const std::string &line : code)
		{
			AddLine(line);
		}
		std::filesystem::path codePath(codePath_s);
		std::ofstream outputPath("Rezult/Compiled_" + codePath.filename().string());
		for(const ForcedLineStatement& line : lines){
			outputPath << line.ToString() << '\n';
		}
		outputPath.close();
	}
};
