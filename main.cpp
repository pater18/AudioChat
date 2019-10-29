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




	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");

	sf::RectangleShape rectangle(sf::Vector2f(750, 75));
	rectangle.setFillColor(sf::Color(128, 128, 128));
	rectangle.setPosition(50, 700);

	sf::RectangleShape rectangleSend(sf::Vector2f(100, 75));
	rectangleSend.setFillColor(sf::Color(128, 128, 128));
	rectangleSend.setPosition(850, 700);

	int moveText = 80;

	std::string test;
	sf::Font font;

	if (!font.loadFromFile("blue.ttf")) {

	}
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Black);

	sf::Text text2;
	text2.setFont(font);
	text2.setCharacterSize(20);
	text2.setFillColor(sf::Color::Black);


	sf::Text send;
	send.setFont(font);
	send.setString("Send");
	send.setCharacterSize(20);
	send.setFillColor(sf::Color::Black);

	sf::Text newline;
	newline.setFont(font);
	newline.setCharacterSize(24);


	/*buffer.loadFromSamples(&sinusAmplituder[0], sinusAmplituder.size(), 1, 44100);
	sound.setBuffer(buffer);
	sound.play();*/

	std::vector<sf::Text> textVector;

	while (window.isOpen())
	{

		text.setPosition(60, 710);
		send.setPosition(880, 725);
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


				textVector.insert(textVector.begin(), text);

				for (size_t i = 0; i < textVector.size(); i++)
				{
					textVector[i].move(0, -moveText);
					
				}
				test.clear();
			}
			break;

			case sf::Event::TextEntered:
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && (event.text.unicode != 13))
						test += (char)event.text.unicode;
					
					float widthOfText = text.getLocalBounds().width + 50;
					sf::Vector2f vector;
					vector = rectangle.getPosition();
					float xRectangle = vector.x;
					float widthRect = xRectangle + rectangle.getSize().x;

					if (widthOfText + 40 >= widthRect) {
						test += "\n";
						widthOfText = 50;
					}

					text.setString(test);
					break;
				}
		}
		window.clear(sf::Color::White);
		window.draw(rectangle);
		window.draw(rectangleSend);
		window.draw(text);
		
			for (auto obj : textVector)
				window.draw(obj);
		window.draw(send);
		window.display();

			}


}
	

	return 0;
}




