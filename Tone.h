#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "StringToBit.h"
#include "Sound.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string> 


std::vector<sf::Int16> message(std::vector<sf::Int16>& samples, int tid, std::vector<sf::Int16> bitstreng)
{
	sf::Sound sound;
	int freq1, freq2;

	freq1 = 1209;
	freq2 = 697;
	for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
	}

	freq1 = 0;
	freq2 = 0;
	for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
	}



	for (int i = 0; i < bitstreng.size(); i += 4) // 0, 4, 8
	{
		if (((bitstreng[i] == 0)) && (bitstreng[i + 1] == 0) && (bitstreng[i + 2]) == 0 && (bitstreng[i + 3] == 0))				//Bit 0000 = 0
		{
			freq1 = 1209;
			freq2 = 697;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}

		}
		if ((bitstreng[i] == 0) && (bitstreng[i + 1] == 0) && (bitstreng[i + 2] == 0) && (bitstreng[i + 3] == 1))			//Bit 0001 = 1
		{
			freq1 = 1209;
			freq2 = 770;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}

		}
		if ((bitstreng[i] == 0) && (bitstreng[i + 1] == 0) && (bitstreng[i + 2] == 1) && (bitstreng[i + 3] == 0))			//Bit 0010 = 2
		{
			freq1 = 1209;
			freq2 = 852;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}
		if ((bitstreng[i] == 0) && (bitstreng[i + 1] == 0) && (bitstreng[i + 2] == 1) && (bitstreng[i + 3] == 1))			//Bit 0011 = 3
		{
			freq1 = 1209;
			freq2 = 941;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}
		if ((bitstreng[i] == 0) && (bitstreng[i + 1] == 1) && (bitstreng[i + 2] == 0) && (bitstreng[i + 3] == 0))			//Bit 0100 = 4
		{
			freq1 = 1336;
			freq2 = 697;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}
		if ((bitstreng[i] == 0) && (bitstreng[i + 1] == 1) && (bitstreng[i + 2] == 0) && (bitstreng[i + 3] == 1))			//Bit 0101 = 5
		{
			freq1 = 1336;
			freq2 = 770;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}
		if ((bitstreng[i] == 0) && (bitstreng[i + 1] == 1) && (bitstreng[i + 2] == 1) && (bitstreng[i + 3] == 0))			//Bit 0110 = 6
		{
			freq1 = 1336;
			freq2 = 852;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}
		if ((bitstreng[i] == 0) && (bitstreng[i + 1] == 1) && (bitstreng[i + 2] == 1) && (bitstreng[i + 3] == 1))			//Bit = 7
		{
			freq1 = 1336;
			freq2 = 941;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}
		if ((bitstreng[i] == 1) && (bitstreng[i + 1] == 0) && (bitstreng[i + 2] == 0) && (bitstreng[i + 3] == 0))			//Bit 1000 = 8
		{
			freq1 = 1447;
			freq2 = 697;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}
		if ((bitstreng[i] == 1) && (bitstreng[i + 1] == 0) && (bitstreng[i + 2] == 0) && (bitstreng[i + 3] == 1))			//Bit = 9
		{
			freq1 = 1447;
			freq2 = 770;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}
		if ((bitstreng[i] == 1) && (bitstreng[i + 1] == 0) && (bitstreng[i + 2] == 1) && (bitstreng[i + 3] == 0))			//Bit = 10
		{
			freq1 = 1447;
			freq2 = 852;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}
		if ((bitstreng[i] == 1) && bitstreng[i + 1] == 0 && (bitstreng[i + 2] == 1) && (bitstreng[i + 3] == 1))			//Bit = 11
		{
			freq1 = 1447;
			freq2 = 941;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}
		if ((bitstreng[i] == 1) && (bitstreng[i + 1] == 1) && (bitstreng[i + 2] == 0) && (bitstreng[i + 3] == 0))			//Bit = 12
		{
			freq1 = 1633;
			freq2 = 697;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}
		if ((bitstreng[i] == 1) && (bitstreng[i + 1] == 1) && (bitstreng[i + 2] == 0) && (bitstreng[i + 3] == 1))			//Bit = 13
		{
			freq1 = 1633;
			freq2 = 770;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}
		if ((bitstreng[i] == 1) && (bitstreng[i + 1] == 1) && (bitstreng[i + 2] == 1) && (bitstreng[i + 3] == 0))			//Bit = 14
		{
			freq1 = 1633;
			freq2 = 852;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}
		if ((bitstreng[i] == 1) && (bitstreng[i + 1] == 1) && (bitstreng[i + 2] == 1) && (bitstreng[i + 3] == 1))			//Bit = 15
		{
			freq1 = 1633;
			freq2 = 941;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				samples.push_back(sound::SineWave(i, freq1, freq2, 0.5));
			}
		}

	}

	return samples;
}




