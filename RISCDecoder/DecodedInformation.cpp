#include "DecodedInformation.h"
#include <iostream>

std::shared_ptr<DecodedInformation> DecodedInformation::getInstance()
{
	static std::shared_ptr<DecodedInformation> decodedInformation(new DecodedInformation);
	return decodedInformation;
}

void DecodedInformation::printInfo()
{
	for (const auto& instruction : this->instructions) {
		std::cout << instruction.op << " " << instruction.operand1 << " " << instruction.operand2 << " " << instruction.operand3 << std::endl;
	}
}
