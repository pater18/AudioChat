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

void Protokol::sendProtokol(std::vector<std::vector<sf::Int16> > _sendBuffer)
{
	customSound test1;

	sf::SoundBuffer buffertest;
	sf::Sound soundtest;
	size_t i = 0;
	std::cout << _sendBuffer.size() << std::endl;

	while ( i <= _sendBuffer.size())
	{

			test1.message(22050, _sendBuffer[i]);
			buffertest.loadFromSamples(&test1._customSound[0], test1._customSound.size(), 1, 44100);
			soundtest.setBuffer(buffertest);
			soundtest.play();
			sf::sleep(sf::seconds(0.5*17));
			test1.slet();

			startClockProt = std::clock();
			while (true)
			{
				duration = (std::clock() - startClockProt) / (double)CLOCKS_PER_SEC;
				//{
				//if ( != sekNR)
				//{
				//	i++;
				// break;
				//}
				if (duration > 4.5)
				{
					soundtest.play();
					startClockProt = std::clock();
					duration = (std::clock() - startClockProt) / (double)CLOCKS_PER_SEC;
				}
			}




			
			
	}

}





std::vector<sf::Int16> Protokol::modtagetProtokol(std::vector<sf::Int16> modtaget)
{
	int startFlag[8] = { 1,1,1,1,0,0,0,0 };

	if ((modtaget[7] == 0) && (modtaget[8] == 0) && (modtaget[9] == 0) && (modtaget[10] == 0) && (modtaget[11] == 0) && (modtaget[12] == 0) && (modtaget[13] == 0) && (modtaget[14] == 0))
	{

		ack.insert(ack.begin(), startFlag, startFlag + 8);
	//Så send x+1 til transmitter
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(0);
	ack.push_back(1);
	ack.insert(ack.end(), startFlag, startFlag + 8);
	//Lav ack om til lyd og send til encoder
}
else if ((modtaget[7] == 0) && (modtaget[8] == 0) && (modtaget[9] == 0) && (modtaget[10] == 0) && (modtaget[11] == 0) && (modtaget[12] == 0) && (modtaget[13] == 0) && (modtaget[14] == 1))
{
		ack.insert(ack.begin(), startFlag, startFlag + 8);
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
	ack.insert(ack.end(), startFlag, startFlag + 8);
}
	return ack;

}
