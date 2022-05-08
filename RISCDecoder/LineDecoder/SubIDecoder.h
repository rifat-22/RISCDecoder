#pragma once

#include "BaseDecoder.h"
#include <memory>

class SubIDecoder : public BaseDecoder {
public:
	SubIDecoder(const std::shared_ptr<BaseDecoder>& nextDecoder = nullptr);
	bool decode(std::string& decodeString) override;
};