#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Encoder
{
public:
	 Encoder();

	std::vector<sf::Int16> StrToBit(std::string input);
	std::vector<sf::Int16> CRC(int antal_bit);

private:
	std::vector<sf::Int16> ud;
protected:
	std::vector<sf::Int16> _Encoded;
};