#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "SoundChunk.h"
#include <vector>
#include <string>
#include "Sound.h"

class Decoder : public SoundChunk
{
public:
	Decoder();
	void intToBit();
	void bitToString();
	std::vector<int> CRC(int); 


private:
	std::vector<int> _CRCok;
	std::vector<int> vecForCRC;
	std::string besked;
};