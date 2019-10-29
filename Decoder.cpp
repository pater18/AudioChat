#include "Decoder.h"
#include <bitset>



Decoder::Decoder()
{
}

void Decoder::intToBit()
{

	std::cout << " Den er her " << std::endl; 
	for (size_t i = 0; i < sendToDecoder.size(); i++)
	{
		std::bitset<4> temp(sendToDecoder[i]);
		std::cout << temp << std::endl;
		vecForCRC.push_back(temp[3]);
		vecForCRC.push_back(temp[2]);
		vecForCRC.push_back(temp[1]);
		vecForCRC.push_back(temp[0]);
	}
	for (size_t i = 0; i < vecForCRC.size(); i++)
	{
		std::cout << vecForCRC[i];
	}
}
