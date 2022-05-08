#pragma once

#include "BaseDecoder.h"
#include <memory>

class AddDecoder : public BaseDecoder {
public:
	AddDecoder(const std::shared_ptr<BaseDecoder>& nextDecoder = nullptr);
	bool decode(std::string& decodeString) override;
};