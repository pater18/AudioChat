#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "StringToBit.h"
#include "Sound.h"
#include "Tone.h"
#include "CRC.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string> 





int main()
{
	std::vector<int> test_a_streng;				//En vektor der skal indeholde den binære sekvens for en streng
	

	StrToBit(test_a_streng, "H");		//Beskeden der skal sendes og den vektor den skal ligge i som 1 og 0. 


	std::vector<sf::Int16> CRC_8;
	CRC(test_a_streng, CRC_8);
	

	sf::SoundBuffer buffer;
	sf::Sound sound;
	
	std::vector<sf::Int16> sinusAmplituder;		
	message(sinusAmplituder, 44100, CRC_8);		//Tager besked vektoren med 1 og 0 og lægger det i en ny vektor, som kan læses af SFML. Hver tone bliver sendt i 1 sekund = 44100. 


	buffer.loadFromSamples(&sinusAmplituder[0], sinusAmplituder.size(), 1, 44100);
	sound.setBuffer(buffer);
	sound.play();
	
	

	//std::cout << testCRC[0] << std::endl; 



	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	
	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
	}

	return 0;
}




