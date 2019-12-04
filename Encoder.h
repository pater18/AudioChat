#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Global.h"

class Encoder
{
public:
	Encoder();
	void setBit(int antalBit);
	void slet();
	std::vector<sf::Int16> StrToBit(sf::String input);
	std::vector<sf::Int16> CRC(std::vector<sf::Int16> bitStrengCRC);
	std::vector<std::vector<sf::Int16> > ESC(std::vector<std::vector<sf::Int16> > bitStrengESC);
	std::vector<std::vector<sf::Int16> > pakker(std::vector<sf::Int16> bitStrengPakker);
	std::vector<std::vector<sf::Int16> > header(std::vector<std::vector<sf::Int16> > headerVec);

	std::vector<std::vector<sf::Int16> > encoderMessage(std::string message);


	
private:
	int m_antalBit;
	std::vector<sf::Int16> m_binStreng;
	std::vector<sf::Int16> m_CRCstreng;
	std::vector<std::vector<sf::Int16> > m_insertESC;
	std::vector<std::vector<sf::Int16> > m_pakker;
	std::vector<std::vector<sf::Int16> > m_pakkerMedHeader;
	int m_numPadding;


protected:



};