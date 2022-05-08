#pragma once

#include "BaseDecoder.h"
#include <memory>

class LiDecoder : public BaseDecoder {
public:
	LiDecoder(const std::shared_ptr<BaseDecoder>& nextDecoder = nullptr);
	bool decode(std::string& decodeString) override;
};