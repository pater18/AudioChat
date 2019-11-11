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
	void setDTMFTone(int DTMF);
	void intToBit();
	void bitToString();
	std::vector<int> CRC(int); 

	std::string besked;

private:
	std::vector<int> m_character;
	std::vector<std::vector<int>> m_charVect;
	const std::vector<int> flag = { 15,0 }, escChar = { 15,14 };
	bool m_listening = true, m_lastEsc = false;

	std::vector<int> _CRCok;
	std::vector<int> vecForCRC;
	
};

