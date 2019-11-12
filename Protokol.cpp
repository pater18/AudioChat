#include "Protokol.h"

#include <math.h>
#include <vector>
#include <string>
#include <string>
#include <bitset>
#include <iostream>


Protokol::Protokol()
{
}

std::vector<sf::Int16> Protokol::sendProtokol(std::vector<std::vector<sf::Int16>> _sendBuffer)
{

	for (size_t i = 0; i < _sendBuffer.size(); i++)
	{
		if (i = 0)
		{
			//customSound::message()




		}
	}

	return std::vector<sf::Int16>();
}




std::vector<sf::Int16> Protokol::modtagetProtokol(std::vector<sf::Int16> modtaget)
{
	if ((modtaget[7] == 0) && (modtaget[8] == 0) && (modtaget[9] == 0) && (modtaget[10] == 0) && (modtaget[11] == 0) && (modtaget[12] == 0) && (modtaget[13] == 0) && (modtaget[14] == 0))
{
	//Så send x+1 til transmitter
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(1);
	//Lav ack om til lyd og send til encoder
}
else if ((modtaget[7] == 0) && (modtaget[8] == 0) && (modtaget[9] == 0) && (modtaget[10] == 0) && (modtaget[11] == 0) && (modtaget[12] == 0) && (modtaget[13] == 0) && (modtaget[14] == 1))
{
	//Så send x til transmitter
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	//Lav ack om til lyd og send til encoder
}
	return ack;

}
