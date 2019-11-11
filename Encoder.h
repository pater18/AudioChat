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
	std::vector<sf::Int16> CRC();
	void opdel();
	void sletFrame();
	int getSize();
	
private:
	std::vector<sf::Int16> ud;
	std::vector<sf::Int16> _Encoded;
	int m_antalBit;
	int StrLenght;
protected:
	std::vector<sf::Int16> opdeltBesked;

	

};