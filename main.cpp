#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Encoder.h"
//#include "StringToBit.h"
#include "Sound.h"
//#include "Tone.h"
//#include "CRC.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string> 





int main()
{
	//std::vector<int> test_a_streng;				//En vektor der skal indeholde den binære sekvens for en streng
	//

	//StrToBit(test_a_streng, "123456789012345678901");		//Beskeden der skal sendes og den vektor den skal ligge i som 1 og 0. 


	std::vector<sf::Int16> CRC_8;
	//CRC(test_a_streng, CRC_8, 32);			// Skal have lavet padding så det er ligegyldigt hvor mange karakter men vælger at skrive.
	//


	customSound koder; 
	

	/*std::vector<sf::Int16> sinusAmplituder;
	Sound::message (sinusAmplituder, 88200, CRC_8);*/		//Tager besked vektoren med 1 og 0 og lægger det i en ny vektor, som kan læses af SFML. Hver tone bliver sendt i 1 sekund = 44100. 

	sf::Event event;

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
					text.setString(test);
					break;
				}
			}
	window.clear();
	window.draw(text);
	
	window.display();
	
		}
		
		
	}
	
	koder.message(41000);
	

	return 0;
}




