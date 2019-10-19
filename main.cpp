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
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

	
	


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

		CustomRecorder recorder;
		recorder.setSaveRecording();

		recorder.start();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		recorder.stop();
		
		break;
	}

	return 0;
}




