#include "Protokol.h"
#include "Decoder.h"
#include "CustomRecorder.h"

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
	CustomRecorder protRecorder;

	
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
			protRecorder.start(10000);
			while (true)
			{
				duration = (std::clock() - startClockProt) / (double)CLOCKS_PER_SEC;
				if (protRecorder.getDecoder().getReceivedMessage())
				{
					protRecorder.stop();
					if (getSekNRSend(protRecorder.getDecoder().getVecAck()) == getSekNRSend(sendBuffer[i]))
					{
						soundtest.play();
						startClockProt = std::clock();
						duration = (std::clock() - startClockProt) / (double)CLOCKS_PER_SEC;
						protRecorder.start(10000);
					}
					else 
					{
						i++;
					}
				}
				
	
				if (duration > 4.5)
				{
					soundtest.play();
					startClockProt = std::clock();
					duration = (std::clock() - startClockProt) / (double)CLOCKS_PER_SEC;
				}
			}




			
			
	}

}

std::vector<sf::Int16> Protokol::getSekNR(std::vector<sf::Int16> _sekNR)
{
	std::vector<sf::Int16> returnSekNR;
	for (int i = 0; i < 8; i++) {
		returnSekNR.push_back(_sekNR[i]);
	}

	return returnSekNR;
}
std::vector<sf::Int16> Protokol::getSekNRSend(std::vector<sf::Int16> _sekNRSend)
{
	std::vector<sf::Int16> returnSekNRSend;
	for (int i = 8; i < 16; i++) {
		returnSekNRSend.push_back(_sekNRSend[i]);
	}

	return returnSekNRSend;
}





std::vector<sf::Int16> Protokol::modtagetProtokol(std::vector<sf::Int16> modtaget)
{
	int startFlag[8] = { 1,1,1,1,0,0,0,0 };
	std::vector<sf::Int16> sekNR0 = { 0,0,0,0,0,0,0,0 };
	std::vector<sf::Int16> sekNR1 = { 0,0,0,0,0,0,0,1 };
	if (getSekNR(modtaget) == sekNR0)
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
else if (getSekNR(modtaget) == sekNR1)
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
