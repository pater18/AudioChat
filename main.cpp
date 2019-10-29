#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Encoder.h"
#include "Sound.h"
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


	sf::Event event;

	//koder.StrToBit("hej med dig ");
	//koder.CRC(32);
	//koder.message(5000);					//Tager besked vektoren med 1 og 0 og l�gger det i en ny vektor, som kan l�ses af SFML. Hver tone bliver sendt i 1 sekund = 44100. 


	sf::SoundBuffer buffer;
	sf::Sound sound;




	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	sf::RectangleShape rectangle(sf::Vector2f(100, 50));
	rectangle.setFillColor(sf::Color::Yellow);
	rectangle.setPosition(250, 275);



	std::string test;
	sf::Font font;

	if (!font.loadFromFile("blue.ttf")) {

	}

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);

	sf::Text newline;
	newline.setFont(font);
	newline.setCharacterSize(24);


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
				if (event.key.code == sf::Keyboard::Enter) {
					customSound koder;
					koder.StrToBit(test);
					koder.CRC(32);
					koder.message(10000);
				buffer.loadFromSamples(&koder._customSound[0], koder._customSound.size(), 1, 44100);
				sound.setBuffer(buffer);
				sound.play();
				
				koder.slet();
				test.clear();
			}
			break;
			case sf::Event::TextEntered:
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && (event.text.unicode != 13))
						test += (char)event.text.unicode;
					
					text.setPosition(250, 275);


					float widthOfText = text.getLocalBounds().width + 250;

					sf::Vector2f vector;

					vector = rectangle.getPosition();

					float xRectangle = vector.x;

					float widthRect = xRectangle + rectangle.getSize().x;

					if (widthOfText >= widthRect) {
						test += "\n";
						widthOfText = 250;
					}

					text.setString(test);
					break;
				}
		}
		window.clear();
		window.draw(rectangle);
		window.draw(text);
		window.display();

			}


}
	

	return 0;
}




