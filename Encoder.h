#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Encoder
{
public:
	 Encoder();

	std::vector<sf::Int16> StrToBit(std::string input);
	std::vector<sf::Int16> CRC(int antal_bit);


	//short SineWave(double time, double freq1, double freq2, double amp);

	
private:
	std::vector<sf::Int16> ud;
protected:
	std::vector<sf::Int16> _Encoded;

	//std::vector<sf::Int16> _Encoded, ud;

};