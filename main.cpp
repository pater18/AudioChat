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

	

	/*std::vector<sf::Int16> sinusAmplituder;
	Sound::message (sinusAmplituder, 88200, CRC_8);*/		//Tager besked vektoren med 1 og 0 og lægger det i en ny vektor, som kan læses af SFML. Hver tone bliver sendt i 1 sekund = 44100. 

	sf::Event event;

	//koder.StrToBit("hej med dig ");
	//koder.CRC(32);
	//koder.message(5000);					//Tager besked vektoren med 1 og 0 og lægger det i en ny vektor, som kan læses af SFML. Hver tone bliver sendt i 1 sekund = 44100. 


	sf::SoundBuffer buffer;
	sf::Sound sound;


	

	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	std::string test;
	sf::Font font;

	if (!font.loadFromFile("blue.ttf")) {

	}

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	
	
	

	/*buffer.loadFromSamples(&sinusAmplituder[0], sinusAmplituder.size(), 1, 44100);
	sound.setBuffer(buffer);
	sound.play();*/
	
	


	
	

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
				if (event.key.code == sf::Keyboard::Escape)
				window.close();
				break;
			case sf::Event::TextEntered:
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128)
						test += (char)event.text.unicode;
					koder.StrToBit(test);
					koder.CRC(32);
					koder.message(5000);

					buffer.loadFromSamples(&koder._customSound[0], koder._customSound.size(), 1, 44100);
					sound.setBuffer(buffer);
					sound.play();

					text.setString(test);
					break;
				}
			}
	window.clear();
	window.draw(text);
	
	window.display();
	
		}
		
		
	}
	
	
	

	return 0;
}




