#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Encoder
{
public:
	Encoder();
	void setBit(int antalBit);
	void slet();
	std::vector<sf::Int16> StrToBit(sf::String input);
	std::vector<sf::Int16> CRC(int antal_bit);
	std::vector<std::vector<sf::Int16> > sendBuffer(std::vector<sf::Int16> _CRC);
	//void tjekDouble();
	std::vector<sf::Int16> insertESC;
	std::vector<std::vector<sf::Int16> > vecSendBuffer;
	
private:

protected:
	std::vector<sf::Int16> _Encoded;
	std::vector<sf::Int16> ud;

};