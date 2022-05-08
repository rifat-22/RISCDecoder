#include "SubDecoder.h"
#include "../DecodedInformation.h"
#include <regex>
#include <iostream>

SubDecoder::SubDecoder(const std::shared_ptr<BaseDecoder>& nextDecoder) : BaseDecoder(nextDecoder)
{
}

bool SubDecoder::decode(std::string& decodeString)
{
	if (this->validLine(decodeString)) {
		std::cmatch matches;
		if (std::regex_search(decodeString.c_str(), matches, std::regex("sub[ ]*(([a-zA-Z][a-zA-Z-0-9]*),[ ]*([a-zA-Z][a-zA-Z-0-9]*),[ ]*([a-zA-Z][a-zA-Z-0-9]+))"))) {
			auto decodedInformation = DecodedInformation::getInstance();
			decodedInformation->insertInstruction("Sub", matches[2].str(), matches[3].str(), matches[4].str());
		}
		else {
			if (this->nextDecoder != nullptr)
				return this->nextDecoder->decode(decodeString);
			return false;
		}
	}
	return false;
}
