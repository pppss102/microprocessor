#include <string>
#include <vector>
#include "Modules.h"

class ProcessorLanguageInterpreter {
	bool _processorType;
	class ForcedLineStatement {
		int lineNr;
		std::string lineName;
		bool MUX[7];
		bool A[7];
		bool B[7];
		bool C[7];
		bool D[7];
		bool E[7];
		bool F[7];
		bool ALU[8];
		bool Reset[9];
		bool DataOut;
		bool CNT;
		bool Flag[4];
		bool Adress[8];

	};
};