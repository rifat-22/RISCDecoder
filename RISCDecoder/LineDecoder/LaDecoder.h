#pragma once

#include "BaseDecoder.h"
#include <memory>

class LaDecoder : public BaseDecoder {
public:
	LaDecoder(const std::shared_ptr<BaseDecoder>& nextDecoder = nullptr);
	bool decode(std::string& decodeString) override;
};