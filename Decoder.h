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
	std::vector<sf::Int16> intToBit(std::vector<int> DTMFtones );
	std::string bitToString(std::vector<sf::Int16> messageInBit);
	std::vector<sf::Int16> CRCmodtaget(int antalBit, std::vector<sf::Int16>);

	bool getCRCstatus() { return m_CRCok; };
	bool getReceivedMessage() { return m_receivedMessage; };
	void setReceivedMessageToFalse() { m_receivedMessage = false; };
	void setReceivedMessageToTrue() { m_receivedMessage = true; };
	std::vector<int> getVecForACK() { return vecForACK; };
	std::vector<sf::Int16> getVecAck() { return m_vecAck; };
	std::string decodeMessage();

	

private:
	std::vector<int> m_character;
	std::vector<int> m_charVect;
	const std::vector<int> flag = { 15,0 }, escChar = { 15,14 };
	bool m_listening = true, m_lastEsc = false;
	bool m_receivedMessage;
	bool m_CRCok = false;

	std::vector<sf::Int16> m_vecForCRC;
	std::vector<int> vecForACK;
	std::vector<sf::Int16> m_vecAck; 
	
};

