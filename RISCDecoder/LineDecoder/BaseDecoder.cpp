#include "BaseDecoder.h"
#include <iostream>

BaseDecoder::BaseDecoder(const std::shared_ptr<BaseDecoder>& nextDecoder)
{
	this->nextDecoder = nextDecoder;
}

bool BaseDecoder::validLine(std::string& decodeString)
{
	try {
		auto ind = decodeString.find_first_of('#');
		if (ind != SIZE_MAX) //To handle no comment found cases
		{
			decodeString = decodeString.erase(ind);
		}
		return true;
	}
	catch (...) {
		return false;
	}
}

bool BaseDecoder::decode(std::string& decodeString)
{
	if (this->validLine(decodeString)) {
		std::cout << decodeString << std::endl;
	}
	std::cout << "Ended" << std::endl;
	return true;
}