#pragma once

#include "BaseDecoder.h"
#include <memory>

class EcallDecoder : public BaseDecoder {
public:
	EcallDecoder(const std::shared_ptr<BaseDecoder>& nextDecoder = nullptr);
	bool decode(std::string& decodeString) override;
};