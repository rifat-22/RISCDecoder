#pragma once

#include <memory>
#include <string>
class BaseDecoder {

public:
	BaseDecoder(const std::shared_ptr<BaseDecoder>& nextDecoder = nullptr);
	virtual bool decode(std::string& decodeString);

protected:
	std::shared_ptr<BaseDecoder> nextDecoder;
	virtual bool validLine(std::string& decodeString);
};