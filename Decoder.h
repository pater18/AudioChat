#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "SoundChunk.h"

class Decoder : public SoundChunk
{
public:
	Decoder();
	void intToBit();


private:
	std::vector<int> vecForCRC;
};