#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Encoder.h"
#include "Sound.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string> 



int main()
{
	

	customSound koder; 
	koder.StrToBit("hej med dig ");
	koder.CRC(32);
	koder.message(5000);					//Tager besked vektoren med 1 og 0 og lægger det i en ny vektor, som kan læses af SFML. Hver tone bliver sendt i 1 sekund = 44100. 

	sf::SoundBuffer buffer;
	sf::Sound sound;

	buffer.loadFromSamples(&koder._customSound[0], koder._customSound.size(), 1, 44100);
	sound.setBuffer(buffer);
	sound.play();
	
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




