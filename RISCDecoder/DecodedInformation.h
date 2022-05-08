#pragma once

#include <vector>
#include <string>
#include <tuple>
#include <memory>

struct Instruction {
	std::string op;
	std::string operand1;
	std::string operand2;
	std::string operand3;
};

class DecodedInformation {
	std::vector<Instruction> instructions;
	DecodedInformation() = default;
	DecodedInformation(DecodedInformation const&) = delete;
	void operator=(DecodedInformation const&) = delete;
public:
	static std::shared_ptr<DecodedInformation> getInstance();
	template <class... Args> void insertInstruction(std::string op, Args ...args);
	void printInfo();
};

template<class ...Args>
void DecodedInformation::insertInstruction(std::string op, Args ...args)
{
	Instruction newInstruction;
	newInstruction.op = op;

	if constexpr (sizeof... (Args) == 2) {
		auto&& list = std::forward_as_tuple(std::forward<Args>(args)...);
		newInstruction.operand1 = std::get<0>(list);
		newInstruction.operand2 = std::get<1>(list);
	}
	else if constexpr (sizeof... (Args) == 3) {
		auto&& list = std::forward_as_tuple(std::forward<Args>(args)...);
		newInstruction.operand1 = std::get<0>(list);
		newInstruction.operand2 = std::get<1>(list);
		newInstruction.operand3 = std::get<2>(list);
	}

	this->instructions.push_back(newInstruction);
}
