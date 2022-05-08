#pragma once

#include "BaseDecoder.h"
#include <memory>

class AddIDecoder : public BaseDecoder {
public:
	AddIDecoder(const std::shared_ptr<BaseDecoder>& nextDecoder = nullptr);
	bool decode(std::string& decodeString) override;
};