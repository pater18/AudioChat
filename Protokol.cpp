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

	while (i <= _sendBuffer.size())
	{

		afspilLyd.playSound(afspilLyd.bitToAmplitudes(44100 / 5, _sendBuffer[i]));

		startClockProt = std::clock();
		protokolRecorder.start(12000);

		bool pakkeIkkeSendt = true;

		while (pakkeIkkeSendt)
		{
			
			duration = (std::clock() - startClockProt) / (double)CLOCKS_PER_SEC;
			if (protokolRecorder.getDecoder().getReceivedMessage())					//Modtager et ackno
			{

				std::cout << "Den er lige over recorder.stop()" << std::endl;
				protokolRecorder.stop();

				if (getSekNR(protokolRecorder.getDecoder().getRenBitStreng()) == getSekNRSend(_sendBuffer[i]))		//Sender den samme besked igen hvis den ikke blev modtaget rigigt i den anden ende
				{
					std::cout << "Den er inde i if sætning" << std::endl;
					protokolRecorder.stop();
					afspilLyd.playSound(afspilLyd.bitToAmplitudes(44100 / 5, _sendBuffer[i]));

					startClockProt = std::clock();
					protokolRecorder.start(12000);
				}
				else																								//Gør klar til at næste pakke kan sendes. 
				{
					std::cout << "Den er inde i else " << std::endl;
					i++;
					pakkeIkkeSendt = false;

				}
			}
			if (duration > 4.5)
			{
				protokolRecorder.stop();
				afspilLyd.playSound(afspilLyd.bitToAmplitudes(44100 / 5, _sendBuffer[i]));
				startClockProt = std::clock();
		
				protokolRecorder.start(12000);
			}
			
			
		}
	}
}

std::vector<sf::Int16>  Protokol::getSekNR(std::vector<sf::Int16> _sekNR)
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





void Protokol::modtagetProtokol(bool& forventetSekNR, std::vector<sf::Int16> modtaget)
{
	if (forventetSekNR == modtaget[7]) 
	{
		int startFlag[8] = { 1,1,1,1,0,0,0,0 };
		std::vector<sf::Int16> sekNR0 = { 0,0,0,0,0,0,0,0 };
		std::vector<sf::Int16> sekNR1 = { 0,0,0,0,0,0,0,1 };
		std::vector<sf::Int16> sekNR3 = { 0,0,0,0,0,0,1,0 };
		std::vector<sf::Int16> sekNR4 = { 0,0,0,0,0,0,1,1 };
		if (getSekNR(modtaget) == sekNR0 || getSekNR(modtaget) == sekNR3)
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
			forventetSekNR = 1; 
		}
		else if (getSekNR(modtaget) == sekNR1 || getSekNR(modtaget) == sekNR4)
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
			forventetSekNR = 0;
		}

		customSound afspilLyd;
		afspilLyd.playSound(bitToAmplitudes(44100 / 5, ack));
		
	}
	else 
	{
		int startFlag[8] = { 1,1,1,1,0,0,0,0 };
		std::vector<sf::Int16> sekNR0 = { 0,0,0,0,0,0,0,0 };
		std::vector<sf::Int16> sekNR1 = { 0,0,0,0,0,0,0,1 };
		std::vector<sf::Int16> sekNR3 = { 0,0,0,0,0,0,1,0 };
		std::vector<sf::Int16> sekNR4 = { 0,0,0,0,0,0,1,1 };
		if (getSekNR(modtaget) == sekNR0 || getSekNR(modtaget) == sekNR3)
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
			ack.push_back(0);
			ack.insert(ack.end(), startFlag, startFlag + 8);
			//Lav ack om til lyd og send til encoder
		}
		else if (getSekNR(modtaget) == sekNR1 || getSekNR(modtaget) == sekNR4)
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
			ack.push_back(1);
			//Lav ack om til lyd og send til encoder
			ack.insert(ack.end(), startFlag, startFlag + 8);

		}

		customSound afspilLyd;
		afspilLyd.playSound(bitToAmplitudes(44100 / 5, ack));

	}
	
	

}
