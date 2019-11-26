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

	CustomRecorder protokolRecorder;
	customSound afspilLyd;

	size_t i = 0;
	std::cout << _sendBuffer.size() << std::endl;

	while (i < _sendBuffer.size())
	{

		afspilLyd.playSound(afspilLyd.bitToAmplitudes(g_sendeTid * 44100, _sendBuffer[i]));

		startClockProt = std::clock();
		protokolRecorder.start(g_samplingFreq);

		bool pakkeIkkeSendt = true;
		protokolRecorder.getDecoder().setReceivedMessageToFalse();
		while (pakkeIkkeSendt)
		{
			if (protokolRecorder.getDecoder().getReceivedMessage())
			{
				protokolRecorder.getDecoder().intToBit(protokolRecorder.getDecoder().getCharVect());

				std::cout << "Den er lige over recorder.stop()" << std::endl;
				protokolRecorder.stop();

				if (getSekNR(protokolRecorder.getDecoder().getRenBitStreng()) == getSekNRSend(_sendBuffer[i]))
				{
					std::cout << "Den er inde i if s�tning" << std::endl;
					protokolRecorder.stop();
					afspilLyd.playSound(afspilLyd.bitToAmplitudes(g_sendeTid * 44100, _sendBuffer[i]));

					startClockProt = std::clock();
					protokolRecorder.start(g_samplingFreq);
				}
				/////////////
				else if (protokolRecorder.getDecoder().getRenBitStreng()[6] == 1)
				{
					std::cout << "Ack for sidste besked modtaget" << std::endl;
						i++;
						pakkeIkkeSendt = false;
				}
				////////////////
				else
				{
					std::cout << "Den er inde i else " << std::endl;
					i++;
					pakkeIkkeSendt = false;

				}
			}

			duration = (std::clock() - startClockProt) / (double)CLOCKS_PER_SEC;
			if (duration > g_sendeTid * 6 + 0.5)
			{
				protokolRecorder.stop();
				afspilLyd.playSound(afspilLyd.bitToAmplitudes(g_sendeTid * 44100, _sendBuffer[i]));
				startClockProt = std::clock();
		
				protokolRecorder.start(g_samplingFreq);
			}
			
		}
	}
}

std::vector<sf::Int16>  Protokol::getSekNR(std::vector<sf::Int16> _sekNR)
{
	std::vector<sf::Int16> returnSekNR;
	std::cout <<"SekNR size" << _sekNR.size() << std::endl;
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





void Protokol::modtagetProtokol(bool &forventetSekNR, std::vector<sf::Int16> modtaget)
{
	int startFlag[8] = { 1,1,1,1,0,0,0,0 };
	std::vector<sf::Int16> sekNR0 = { 0,0,0,0,0,0,0,0 };
	std::vector<sf::Int16> sekNR1 = { 0,0,0,0,0,0,0,1 };
	std::vector<sf::Int16> sekNR11 = { 0,0,0,0,0,0,1,1 };
	std::cout << "modtage size" << modtaget.size() << std::endl;
	if (forventetSekNR == modtaget[7] || modtaget[6] == 1)
	{
		

		if (getSekNR(modtaget) == sekNR0)
		{
			ack.insert(ack.begin(), startFlag, startFlag + 8);
			//S� send x+1 til transmitter
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
			forventetSekNR = 1;
		}
		else if (getSekNR(modtaget) == sekNR1)
		{
			ack.insert(ack.begin(), startFlag, startFlag + 8);
			//S� send x til transmitter
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
			forventetSekNR = 0;
		}
		else if (getSekNR(modtaget) == sekNR11)
		{
			ack.insert(ack.begin(), startFlag, startFlag + 8);
			//S� send x til transmitter
			ack.push_back(0);
			ack.push_back(0);
			ack.push_back(0);
			ack.push_back(0);
			ack.push_back(0);
			ack.push_back(0);
			ack.push_back(1);
			ack.push_back(0);
			//Lav ack om til lyd og send til encoder
			ack.insert(ack.end(), startFlag, startFlag + 8);
			forventetSekNR = 0;
		}
		
		
	}
	else
	{
		ack.insert(ack.begin(), startFlag, startFlag + 8);
		//S� send x+1 til transmitter
		ack.push_back(0);
		ack.push_back(0);
		ack.push_back(0);
		ack.push_back(0);
		ack.push_back(0);
		ack.push_back(0);
		ack.push_back(0);
		ack.push_back(forventetSekNR);
		ack.insert(ack.end(), startFlag, startFlag + 8);
		//Lav ack om til lyd og send til encoder
	}

	
	customSound afspilLyd;
	afspilLyd.playSound(bitToAmplitudes(g_sendeTid * 44100, ack));
}
