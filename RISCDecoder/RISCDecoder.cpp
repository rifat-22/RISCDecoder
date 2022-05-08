// RISCDecoder.cpp : Defines the entry point for the application.
//

#include "RISCDecoder.h"
#include "LineDecoder/BaseDecoder.h"
#include "LineDecoder/AddDecoder.h"
#include "LineDecoder/AddIDecoder.h"
#include "LineDecoder/SubDecoder.h"
#include "LineDecoder/SubIDecoder.h"
#include "LineDecoder/LaDecoder.h"
#include "LineDecoder/LiDecoder.h"
#include "LineDecoder/EcallDecoder.h"
#include "DecodedInformation.h"
#include <string>
#include <fstream>

int main()
{
	std::string fileLocation;
	std::cout << "Assembly file location: ";
	std::cin >> fileLocation;

	std::ifstream fileInput{fileLocation};

	std::shared_ptr<LiDecoder> liDecoder = std::make_shared<LiDecoder>();
	std::shared_ptr<LaDecoder> laDecoder = std::make_shared<LaDecoder>(liDecoder);
	std::shared_ptr<AddDecoder> addDecoder = std::make_shared<AddDecoder>(laDecoder);
	std::shared_ptr<AddIDecoder> addIDecoder = std::make_shared<AddIDecoder>(addDecoder);
	std::shared_ptr<SubDecoder> subDecoder = std::make_shared<SubDecoder>(addIDecoder);
	std::shared_ptr<SubIDecoder> subIDecoder = std::make_shared<SubIDecoder>(subDecoder);
	std::shared_ptr<EcallDecoder> ecallDecoder = std::make_shared<EcallDecoder>(subIDecoder);

	for (std::string line; std::getline(fileInput, line); )
	{
		ecallDecoder->decode(line);
	}

	auto decodedInformation = DecodedInformation::getInstance();
	decodedInformation->printInfo();
}
