#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Sound.h"
#include <vector>


class Protokol : public customSound
{
public:

	Protokol();
	std::vector<sf::Int16> modtagetProtokol(std::vector<sf::Int16> modtaget);
	std::vector<sf::Int16> ack;
	void sendProtokol(std::vector<std::vector<sf::Int16> > _sendBuffer);

private:

	std::vector<std::vector<sf::Int16> > sendBuffer;



};

