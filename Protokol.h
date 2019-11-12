#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Sound.h"

class Protokol
{
public:

	Protokol();

	std::vector<sf::Int16> sendProtokol(std::vector<std::vector<sf::Int16> > _sendBuffer);

private:

	std::vector<std::vector<sf::Int16> > sendBuffer;


};

