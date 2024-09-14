#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include "Modules.h"
#include "Utils.h"

class ForcedLineStatement
{
	void ALUFunction(const std::string &function)
	{
		A[(int)Modules::Register::S_Data] = 1;
		if(function.find('1') != std::string::npos)
		{
			if(function.find('+') != std::string::npos)
			{
				if(function.find('A') != std::string::npos)
				{
					ALU[(int)Modules::ALU::Rp1] = 1;
				} else
				{
					ALU[(int)Modules::ALU::Lp1] = 1;
				}
			} else
			{
				if(function.find('A') != std::string::npos)
				{
					ALU[(int)Modules::ALU::Rm1] = 1;
				} else
				{
					ALU[(int)Modules::ALU::Lm1] = 1;
				}
			}
			return;
		}
		if(function.find('N') != std::string::npos)
		{
			if(function.find('A') != std::string::npos)
			{
				ALU[(int)Modules::ALU::NotR] = 1;
			} else
			{
				ALU[(int)Modules::ALU::NotL] = 1;
			}
			return;
		}
		if(function.find('X') != std::string::npos)
		{
			ALU[(int)Modules::ALU::LxorR] = 1;
			return;
		}
		ALU[(int)Modules::ALU::LpR] = 1;
	}
	void AssignFunction(const std::string &part)
	{
		std::vector<std::string> BothSides = split(part, "=");
		if(BothSides[0].find('A') != std::string::npos && BothSides[0].length() > 1)
		{
			std::cout << "Tried to assign A and something else";
			return;
		}

		if(BothSides[0].find('A') != std::string::npos)
		{
			ALUFunction(BothSides[1]);
		}
		if(BothSides[0].find('B') != std::string::npos)
		{
			B[(int)Modules::Register::S_Data] = 1;
		}
		if(BothSides[0].find('C') != std::string::npos)
		{
			C[(int)Modules::Register::S_Data] = 1;
		}
		if(BothSides[0].find('D') != std::string::npos)
		{
			D[(int)Modules::Register::S_Data] = 1;
		}
		if(BothSides[0].find('E') != std::string::npos)
		{
			E[(int)Modules::Register::S_Data] = 1;
		}
		if(BothSides[0].find('F') != std::string::npos)
		{
			F[(int)Modules::Register::S_Data] = 1;
		}

		if(BothSides[1].find("DIN") != std::string::npos)
		{
			MUX[(int)Modules::MUX::Din] = 1;
		} else if(BothSides[1].find('B') != std::string::npos)
		{
			MUX[(int)Modules::MUX::RegB] = 1;
		} else if(BothSides[1].find('C') != std::string::npos)
		{
			MUX[(int)Modules::MUX::RegC] = 1;
		} else if(BothSides[1].find('D') != std::string::npos)
		{
			MUX[(int)Modules::MUX::RegD] = 1;
		} else if(BothSides[1].find('E') != std::string::npos)
		{
			MUX[(int)Modules::MUX::RegE] = 1;
		} else if(BothSides[1].find('F') != std::string::npos)
		{
			MUX[(int)Modules::MUX::RegF] = 1;
		} else
		{
			MUX[(int)Modules::MUX::RegA] = 1;
		}
	}
	void ResetFunction(const std::string &part)
	{
		std::vector<std::string> Resets = split(part.substr(4, part.length() - 5), ",");
		if(std::find(Resets.begin(), Resets.end(), "A") != Resets.end())
		{
			Reset[(int)Modules::RST::RegA] = 1;
		}
		if(std::find(Resets.begin(), Resets.end(), "B") != Resets.end())
		{
			Reset[(int)Modules::RST::RegB] = 1;
		}
		if(std::find(Resets.begin(), Resets.end(), "C") != Resets.end())
		{
			Reset[(int)Modules::RST::RegC] = 1;
		}
		if(std::find(Resets.begin(), Resets.end(), "D") != Resets.end())
		{
			Reset[(int)Modules::RST::RegD] = 1;
		}
		if(std::find(Resets.begin(), Resets.end(), "E") != Resets.end())
		{
			Reset[(int)Modules::RST::RegE] = 1;
		}
		if(std::find(Resets.begin(), Resets.end(), "F") != Resets.end())
		{
			Reset[(int)Modules::RST::RegF] = 1;
		}
		if(std::find(Resets.begin(), Resets.end(), "CNT") != Resets.end())
		{
			Reset[(int)Modules::RST::CNT] = 1;
		}
		if(std::find(Resets.begin(), Resets.end(), "ROM") != Resets.end())
		{
			Reset[(int)Modules::RST::ROM] = 1;
		}
		if(std::find(Resets.begin(), Resets.end(), "FLAG") != Resets.end())
		{
			Reset[(int)Modules::RST::Flag] = 1;
		}
	}
	void FlagFunction(const std::string &part)
	{
		if(part.find("0") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::FALSE);
			return;
		}
		if(part.find("CNT") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::CNT);
			return;
		}
		if(part.find("AH") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::AH);
			return;
		}
		if(part.find("AL") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::AL);
			return;
		}
		if(part.find("BH") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::BH);
			return;
		}
		if(part.find("BL") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::BL);
			return;
		}
		if(part.find("CH") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::CH);
			return;
		}
		if(part.find("CL") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::CL);
			return;
		}
		if(part.find("DH") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::DH);
			return;
		}
		if(part.find("DL") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::DL);
			return;
		}
		if(part.find("EH") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::EH);
			return;
		}
		if(part.find("EL") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::EL);
			return;
		}
		if(part.find("FH") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::FH);
			return;
		}
		if(part.find("FL") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::FL);
			return;
		}
		if(part.find("ALU") != std::string::npos)
		{
			AssignIntToBoolArray(Flag, 4, (int)Modules::Flag::ALU);
			return;
		}
	}
	void ShiftFunction(const std::string &part)
	{
		int shiftAssign = 0;
		std::string shift = part.substr(0, 3);
		if(shift == "LL1")
		{
			shiftAssign = (int)Modules::Register::LL1;
		} else if(shift == "LR1")
		{
			shiftAssign = (int)Modules::Register::LR1;
		} else if(shift == "AL1")
		{
			shiftAssign = (int)Modules::Register::AL1;
		} else if(shift == "AR1")
		{
			shiftAssign = (int)Modules::Register::AR1;
		} else if(shift == "CL1")
		{
			shiftAssign = (int)Modules::Register::CL1;
		} else if(shift == "CR1")
		{
			shiftAssign = (int)Modules::Register::CR1;
		}
		std::vector<std::string> registers = split(part.substr(4, part.length() - 5), ",");
		if(std::find(registers.begin(), registers.end(), "A") != registers.end())
		{
			A[shiftAssign] = 1;
		}
		if(std::find(registers.begin(), registers.end(), "B") != registers.end())
		{
			B[shiftAssign] = 1;
		}
		if(std::find(registers.begin(), registers.end(), "C") != registers.end())
		{
			C[shiftAssign] = 1;
		}
		if(std::find(registers.begin(), registers.end(), "D") != registers.end())
		{
			D[shiftAssign] = 1;
		}
		if(std::find(registers.begin(), registers.end(), "E") != registers.end())
		{
			E[shiftAssign] = 1;
		}
		if(std::find(registers.begin(), registers.end(), "F") != registers.end())
		{
			F[shiftAssign] = 1;
		}
	}
	void NextLineFunction(const std::string& part)
	{
		std::string number_string = part.substr(5);
		int number = std::stoi(number_string);
		nextLineNr = number;
		AssignIntToBoolArray(Adress, 8, number);
	}
	void ThisLineFunction(const std::string &part)
	{
		int number = std::stoi(part);
		lineNr = number;
	}

	void PartInterpreter(const std::string &part)
	{
		if(part.find("=") != std::string::npos)
		{
			AssignFunction(part);
			return;
		}
		if(part == "CNT--")
		{
			CNT = true;
			return;
		}
		if(part.find("RST") != std::string::npos)
		{
			ResetFunction(part);
			return;
		}
		if(part.find("LS") != std::string::npos)
		{
			FlagFunction(part);
			return;
		}
		if(part.find("NEXT:") != std::string::npos)
		{
			NextLineFunction(part);
			return;
		}
		if(part.find("DONE") != std::string::npos)
		{
			DataOut = 1;
			AssignIntToBoolArray(Adress, 8, lineNr);
			nextLineNr = lineNr;
			return;
		}
		std::string shiftCheck = part.substr(0, 3);
		if(shiftCheck == "LL1" || shiftCheck == "LR1" || shiftCheck == "AL1" || shiftCheck == "AR1" || shiftCheck == "CL1" || shiftCheck == "CR1")
		{
			ShiftFunction(part);
			return;
		}
		ThisLineFunction(part);
	}
public:
	int lineNr{-1};
	int nextLineNr{-1};
	std::string lineName{};
	bool MUX[7]{};
	bool A[7]{};
	bool B[7]{};
	bool C[7]{};
	bool D[7]{};
	bool E[7]{};
	bool F[7]{};
	bool ALU[8]{};
	bool Reset[9]{};
	bool DataOut{};
	bool CNT{};
	bool Flag[4]{};
	bool Adress[8]{};
	ForcedLineStatement(std::string line)
	{
		std::transform(line.begin(), line.end(), line.begin(), ::toupper);
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
		std::vector<std::string> parts = split(line, ";");
		for(std::string part : parts)
		{
			PartInterpreter(part);
		}
		if(nextLineNr < 0)
		{
			AssignIntToBoolArray(Adress, 8, lineNr + 1);
		}
	}
	std::string ToString() const
	{
		std::string rez = std::to_string(lineNr) + "=> \"";
		rez += BoolArrayToString(MUX, 7);
		rez += BoolArrayToString(A, 7);
		rez += BoolArrayToString(B, 7);
		rez += BoolArrayToString(C, 7);
		rez += BoolArrayToString(D, 7);
		rez += BoolArrayToString(E, 7);
		rez += BoolArrayToString(F, 7);
		rez += BoolArrayToString(ALU, 8);
		rez += BoolArrayToString(Reset, 9);
		rez += std::to_string(DataOut);
		rez += std::to_string(CNT);
		rez += BoolArrayToString(Flag, 4);
		rez += BoolArrayToString(Adress, 8);
		rez += "\", --Comment";
		return rez;
	}
};
