#pragma once

#include "BaseDecoder.h"
#include <memory>

class SubDecoder : public BaseDecoder {
public:
	SubDecoder(const std::shared_ptr<BaseDecoder>& nextDecoder = nullptr);
	bool decode(std::string& decodeString) override;
};