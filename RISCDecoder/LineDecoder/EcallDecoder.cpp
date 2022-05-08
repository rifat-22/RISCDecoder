#include "EcallDecoder.h"
#include "../DecodedInformation.h"
#include <regex>
#include <iostream>

EcallDecoder::EcallDecoder(const std::shared_ptr<BaseDecoder>& nextDecoder) : BaseDecoder(nextDecoder)
{
}

bool EcallDecoder::decode(std::string& decodeString)
{
	if (this->validLine(decodeString)) {
		std::cmatch matches;
		if (std::regex_search(decodeString.c_str(), matches, std::regex("ecall[ ]*"))) {
			auto decodedInformation = DecodedInformation::getInstance();
			decodedInformation->insertInstruction("Ecall");
		}
		else {
			return this->nextDecoder->decode(decodeString);
		}
	}
	return false;
}
