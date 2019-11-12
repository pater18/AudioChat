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
	
protected:
	std::vector<sf::Int16> _Encoded;
	std::vector<sf::Int16> ud;
	

};