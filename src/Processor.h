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
	void AddLine(const std::string &line, Modules::Processor type)
	{
		ForcedLineStatement newLine(line, type);
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
		Modules::Processor processorType{};
		if (code[0] == "F")
		{
			processorType = Modules::Processor::Forced;
		}
		else
		{
			processorType = Modules::Processor::Natural;
		}
		for (int i = 1; i < code.size(); i++)
		{
			AddLine(code[i], processorType);
		}
		std::filesystem::path codePath(codePath_s);
		std::ofstream outputPath("Rezult/Compiled_" + code[0] + "_" + codePath.filename().string());
		for (const ForcedLineStatement &line : lines)
		{
			outputPath << line.ToString() << '\n';
		}
		outputPath.close();
	}
};
