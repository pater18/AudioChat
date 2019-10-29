#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "SoundChunk.h"
#include <vector>

class Decoder : public SoundChunk
{
public:
	Decoder();
	void intToBit();
	void bitToString();
	std::vector<int> CRC(int); 


private:
	std::vector<int> _CRC;
	std::vector<int> vecForCRC;
};