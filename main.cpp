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



	customSound koder;


	sf::Event event;

	koder.StrToBit("");
	koder.CRC(32);
	//koder.tjekDouble();						//Virker kun hvis der er noget i strengen ovenover.
	koder.message(22050);					//Tager besked vektoren med 1 og 0 og l�gger det i en ny vektor, som kan l�ses af SFML. Hver tone bliver sendt i 1 sekund = 44100. 
	 


	sf::SoundBuffer buffer;
	sf::Sound sound;

	buffer.loadFromSamples(&koder._customSound[0], koder._customSound.size(), 1, 44100);
	sound.setBuffer(buffer);
	sound.play();



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
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:

				if (event.key.code == sf::Keyboard::Enter)
				{
					//koder.StrToBit("");
					//koder.CRC(32);
					//koder.message(4410);					//Tager besked vektoren med 1 og 0 og l�gger det i en ny vektor, som kan l�ses af SFML. Hver tone bliver sendt i 1 sekund = 44100. 
					//buffer.loadFromSamples(&koder._customSound[0], koder._customSound.size(), 1, 44100);
					//sound.setBuffer(buffer);
					//sound.play();
				}
				break;

			}

			if (!sf::SoundBufferRecorder::isAvailable())
			{
				std::cout << "Error";
			}



			CustomRecorder recorder;
			//recorder.setSaveRecording();

			recorder.start(10000);
			std::this_thread::sleep_for(std::chrono::milliseconds(100000));
			recorder.stop();


		
		

		}
		window.clear();
		window.draw(text);
		window.display();
	}

	if (!sf::SoundBufferRecorder::isAvailable())
	{
		std::cout << "Error";
	}

	CustomRecorder recorder;
	recorder.setSaveRecording();

	recorder.start();
	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	recorder.stop();
	Decoder temp;
	temp.intToBit();






	return 0;
}







