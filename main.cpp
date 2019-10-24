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
	

	sf::SoundBuffer buffer;
	sf::Sound sound;
	
	



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




