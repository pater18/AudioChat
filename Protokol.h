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

	void sendProtokol(std::vector<std::vector<sf::Int16> > _sendBuffer);
	std::vector<sf::Int16> getSekNR(std::vector<sf::Int16> _sekNR);
	std::vector<sf::Int16> getSekNRSend(std::vector<sf::Int16> _sekNRSend);


	std::clock_t startClockProt;

private:
	double duration;
	std::vector<std::vector<sf::Int16> > sendBuffer;
	std::vector<sf::Int16> ack;


};

