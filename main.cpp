#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Encoder.h"
#include "Sound.h"
#include "CustomRecorder.h"
#include "Decoder.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string> 
#include <thread>
#include <chrono>




int main()
{



	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	std::string test;
	sf::Font font;

	//if (!font.loadFromFile("blue.ttf")) {

	//}

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);



	



	while (window.isOpen())
	{
		
		if (!sf::SoundBufferRecorder::isAvailable())
		{
				std::cout << "Error";
		}

		CustomRecorder recorder;
		recorder.setSaveRecording();
		
		recorder.start(10000);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		recorder.stop();

		std::this_thread::sleep_for(std::chrono::milliseconds(10000));
		window.clear();
		window.draw(text);
		window.display();
	}


	return 0;
}







