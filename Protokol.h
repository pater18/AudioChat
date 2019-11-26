#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Sound.h"
#include "CustomRecorder.h"
#include <vector>
#include "Global.h"


class Protokol : public customSound
{
public:

	Protokol();
	void modtagetProtokol(bool &forventetSekNR, std::vector<sf::Int16> modtaget);

	void sendProtokol(std::vector<std::vector<sf::Int16> > _sendBuffer, CustomRecorder& protokolRecorder);
	std::vector<sf::Int16> getSekNR(std::vector<sf::Int16> _sekNR);
	std::vector<sf::Int16> getSekNRSend(std::vector<sf::Int16> _sekNRSend);


	std::clock_t startClockProt;

private:
	double duration;
	std::vector<std::vector<sf::Int16> > sendBuffer;
	std::vector<sf::Int16> ack;


};

