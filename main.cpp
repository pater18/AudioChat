#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "StringToBit.h"
#include "Sound.h"
#include "Tone.h"
#include "CustomRecorder.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string> 
#include <thread>
#include <chrono>





int main()
{

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (!sf::SoundBufferRecorder::isAvailable())
		{
			std::cout << "Error";
		}

		
		break;
	}

	return 0;
}




