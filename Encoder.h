#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Encoder
{
public:
	Encoder();
	void slet();
	std::vector<sf::Int16> StrToBit(sf::String input);
	std::vector<sf::Int16> CRC(int antal_bit);
	//void tjekDouble();



	
private:
	std::vector<sf::Int16> ud;
protected:
	std::vector<sf::Int16> _Encoded;

	

};