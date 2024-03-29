#include "Sound.h"
#include <math.h>
#include "Encoder.h"



customSound::customSound()
{
}

short customSound::Sinewave(double time, double freq1, double freq2, double amp)
{
	const double TWOPI = 6.283185307;
	short result1;
	double tpc1 = 44100 / freq1;
	double cycles1 = time / tpc1;
	double rad1 = TWOPI * cycles1;
	short amplitude = 32767 * amp;
	result1 = amplitude * sin(rad1);

	short result2;
	double tpc2 = 44100 / freq2;
	double cycles2 = time / tpc2;
	double rad2 = TWOPI * cycles2;
	result2 = amplitude * sin(rad2);

	_result = result1 + result2;

	return _result;
}


  


std::vector<sf::Int16> customSound::message(int tid, std::vector<sf::Int16> vecFraProt)
{

	

	std::vector <std::vector<int>> freq{ {697, 1209},{697, 1336},{697, 1477},{697, 1633},{ 770, 1209},{ 770, 1336},{ 770, 1477},{ 770, 1633},{852, 1209},{852, 1336},{852, 1477},{852, 1633}, {941, 1209},{941, 1336},{941, 1477},{941, 1633} };

	int freq1, freq2;

	for (int i = 0; i < vecFraProt.size(); i += 4) // 0, 4, 8
	{
		if ((vecFraProt[i] == 0) && (vecFraProt[i + 1] == 0) && (vecFraProt[i + 2] == 0) && (vecFraProt[i + 3] == 0))			//Bit 0000 = 0
		{
			freq1 = 697;
			freq2 = 1209;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}

		}

		if ((vecFraProt[i] == 0) && (vecFraProt[i + 1] == 0) && (vecFraProt[i + 2] == 0) && (vecFraProt[i + 3] == 1))			//Bit 0001 = 1
		{
			freq1 = 697;
			freq2 = 1336;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}

		}
    
		if ((vecFraProt[i] == 0) && (vecFraProt[i + 1] == 0) && (vecFraProt[i + 2] == 1) && (vecFraProt[i + 3] == 0))			//Bit 0010 = 2
		{
			freq1 = 697;
			freq2 = 1477;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}

		if ((vecFraProt[i] == 0) && (vecFraProt[i + 1] == 0) && (vecFraProt[i + 2] == 1) && (vecFraProt[i + 3] == 1))			//Bit 0011 = 3
		{
			freq1 = 697;
			freq2 = 1633;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}

		if ((vecFraProt[i] == 0) && (vecFraProt[i + 1] == 1) && (vecFraProt[i + 2] == 0) && (vecFraProt[i + 3] == 0))			//Bit 0100 = 4
		{
			freq1 = 770;
			freq2 = 1209;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
    
		if ((vecFraProt[i] == 0) && (vecFraProt[i + 1] == 1) && (vecFraProt[i + 2] == 0) && (vecFraProt[i + 3] == 1))			//Bit 0101 = 5
		{
			freq1 = 770;
			freq2 = 1336;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}

		if ((vecFraProt[i] == 0) && (vecFraProt[i + 1] == 1) && (vecFraProt[i + 2] == 1) && (vecFraProt[i + 3] == 0))			//Bit 0110 = 6
		{
			freq1 = 770;
			freq2 = 1477;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}

		if ((vecFraProt[i] == 0) && (vecFraProt[i + 1] == 1) && (vecFraProt[i + 2] == 1) && (vecFraProt[i + 3] == 1))			//Bit = 7
		{
			freq1 = 770;
			freq2 = 1633;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}

		if ((vecFraProt[i] == 1) && (vecFraProt[i + 1] == 0) && (vecFraProt[i + 2] == 0) && (vecFraProt[i + 3] == 0))			//Bit 1000 = 8
		{
			freq1 = 852;
			freq2 = 1209;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}

		if ((vecFraProt[i] == 1) && (vecFraProt[i + 1] == 0) && (vecFraProt[i + 2] == 0) && (vecFraProt[i + 3] == 1))			//Bit = 9
		{
			freq1 = 852;
			freq2 = 1336;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}

		if ((vecFraProt[i] == 1) && (vecFraProt[i + 1] == 0) && (vecFraProt[i + 2] == 1) && (vecFraProt[i + 3] == 0))			//Bit = 10
		{
			freq1 = 852;
			freq2 = 1477;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}

		if ((vecFraProt[i] == 1) && vecFraProt[i + 1] == 0 && (vecFraProt[i + 2] == 1) && (vecFraProt[i + 3] == 1))			//Bit = 11
		{
			freq1 = 852;
			freq2 = 1633;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
    
		if ((vecFraProt[i] == 1) && (vecFraProt[i + 1] == 1) && (vecFraProt[i + 2] == 0) && (vecFraProt[i + 3] == 0))			//Bit = 12
		{
			freq1 = 941;
			freq2 = 1209;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}

		if ((vecFraProt[i] == 1) && (vecFraProt[i + 1] == 1) && (vecFraProt[i + 2] == 0) && (vecFraProt[i + 3] == 1))			//Bit = 13
		{
			freq1 = 941;
			freq2 = 1336;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}

		if ((vecFraProt[i] == 1) && (vecFraProt[i + 1] == 1) && (vecFraProt[i + 2] == 1) && (vecFraProt[i + 3] == 0))			//Bit = 14
		{
			freq1 = 941;
			freq2 = 1477;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}

		if ((vecFraProt[i] == 1) && (vecFraProt[i + 1] == 1) && (vecFraProt[i + 2] == 1) && (vecFraProt[i + 3] == 1))			//Bit = 15
		{
			freq1 = 941;
			freq2 = 1633;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}

	}

	return _customSound;

}

std::vector<sf::Int16> customSound::testAfLyd(int tid, std::vector<sf::Int16> &decimaler)
{
	sf::SoundBuffer buffer;
	sf::Sound sound;
	std::vector<sf::Int16> lyde;
	std::vector <std::vector<int>> freq{ {697, 1209},{697, 1336},{697, 1477},{697, 1633},{ 770, 1209},{ 770, 1336},{ 770, 1477},{ 770, 1633},{852, 1209},{852, 1336},{852, 1477},{852, 1633}, {941, 1209},{941, 1336},{941, 1477},{941, 1633} };

	int freq1, freq2;



	for (int i = 0; i < decimaler.size(); i++) // 0, 4, 8
	{

		freq1 = freq[ decimaler[i] ] [0];
		freq2 = freq[ decimaler[i] ] [1];
		for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
		{
			lyde.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
		}
	}


	return lyde;
	std::cout << lyde.size() << std::endl;
	


}