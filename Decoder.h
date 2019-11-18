#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "SoundChunk.h"
#include "Timer.h"
#include "Sound.h"

#include <vector>
#include <string>

class Decoder : public SoundChunk
{
public:
	Decoder();
	void setDTMFTone(int DTMF);
	std::vector<sf::Int16> intToBit();
	std::string bitToString();
	std::vector<int> CRC(int); 
	bool getReceivedMessage() { return m_receivedMessage; };
	void setReceivedMessageToFalse() { m_receivedMessage = false; };
	void setReceivedMessageToTrue() { m_receivedMessage = true; };
	std::string getBesked() { return besked; };
	std::vector<int> getVecForACK() { return vecForACK; };
	std::vector<sf::Int16> getVecAck() { return m_vecAck; };
	std::string besked;

private:
	std::vector<int> m_character;
	std::vector<int> m_charVect;
	const std::vector<int> flag = { 15,0 }, escChar = { 15,14 };
	bool m_listening = true, m_lastEsc = false;
	bool m_receivedMessage;

	std::vector<int> _CRCok;
	std::vector<sf::Int16> vecForCRC;
	std::vector<int> vecForACK;
	std::vector<sf::Int16> m_vecAck; 
	
};

