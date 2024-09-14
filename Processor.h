#pragma once

#include <string>
#include <vector>
#include <algorithm>
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
	void AddLine(const std::string& line)
	{
		ForcedLineStatement newLine(line);
		lines.push_back(newLine);
	}
	void PrintToConsole()
	{
		for(const ForcedLineStatement &line : lines)
		{
			std::cout << line.ToString() << '\n';
		}
	}
};
