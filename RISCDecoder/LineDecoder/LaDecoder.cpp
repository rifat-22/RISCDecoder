#include "LaDecoder.h"
#include "../DecodedInformation.h"
#include <regex>
#include <iostream>

LaDecoder::LaDecoder(const std::shared_ptr<BaseDecoder>& nextDecoder) : BaseDecoder(nextDecoder)
{
}

bool LaDecoder::decode(std::string& decodeString)
{
	if (this->validLine(decodeString)) {
		std::cmatch matches;
		if (std::regex_search(decodeString.c_str(), matches, std::regex("la[ ]*(([a-zA-Z][a-zA-Z-0-9]*),[ ]*([a-zA-Z][a-zA-Z-0-9]+))"))) {
			auto decodedInformation = DecodedInformation::getInstance();
			decodedInformation->insertInstruction("La", matches[2].str(), matches[3].str());
		}
		else {
			if (this->nextDecoder != nullptr)
				return this->nextDecoder->decode(decodeString);
			return false;
		}
	}
	return false;
}
