#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class Protokol
{
public:

	Protokol();
	std::vector<sf::Int16> modtagetProtokol(std::vector<sf::Int16> modtaget);
	std::vector<sf::Int16> ack;

private:

	

};

