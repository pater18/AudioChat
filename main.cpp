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




	//customSound koder;


	//sf::Event event;

	//koder.StrToBit("");
	//koder.CRC(32);
	////koder.tjekDouble();						//Virker kun hvis der er noget i strengen ovenover.
	//koder.message(8820);					//Tager besked vektoren med 1 og 0 og l�gger det i en ny vektor, som kan l�ses af SFML. Hver tone bliver sendt i 1 sekund = 44100. 
	// 
	//sf::SoundBuffer buffer;
	//sf::Sound sound;

	//buffer.loadFromSamples(&koder._customSound[0], koder._customSound.size(), 1, 44100);
	//sound.setBuffer(buffer);
	//sound.play();
	sf::SoundBuffer buffer;
	sf::Sound sound;

	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");

	sf::RectangleShape rectangle(sf::Vector2f(750, 75));
	rectangle.setFillColor(sf::Color(128, 128, 128));
	rectangle.setPosition(50, 700);


	sf::RectangleShape rectangleSend(sf::Vector2f(100, 75));
	rectangleSend.setFillColor(sf::Color(128, 128, 128));
	rectangleSend.setPosition(850, 700);


	double widthOfText = 0;
	sf::RectangleShape rectangleBesked(sf::Vector2f(100, 35));

	std::vector<sf::Text> textVector;
	std::vector<sf::Text> textVector2;
	std::vector<sf::RectangleShape> rectangleVec;
	std::vector<sf::RectangleShape> rectangleVec2;
	std::vector< std::pair< sf::Text, sf::RectangleShape> > textRect;
	sf::Vector2f xyvec;


	int moveText = 80;

	sf::Font font;

	font.loadFromFile("blue.ttf");

	std::string test;
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Black);
	text.setPosition(60, 710);

	double widthOfReceive;
	std::string receive = "Hej med dig";
	sf::Text text2;
	text2.setFont(font);
	text2.setCharacterSize(20);
	text2.setFillColor(sf::Color::Black);


	sf::Text send;
	send.setFont(font);
	send.setString("Send");
	send.setCharacterSize(20);
	send.setFillColor(sf::Color::Black);
	send.setPosition(880, 725);

	sf::Text newline;
	newline.setFont(font);
	newline.setCharacterSize(24);
	newline.setString("\n");



	while (window.isOpen())
	
	{

		//CustomRecorder recorder;
		//recorder.start();
		//
		//std::this_thread::sleep_for(std::chrono::milliseconds(6000));
		//recorder.stop();
		//std::this_thread::sleep_for(std::chrono::milliseconds(10000));

	

		sf::Event event;
		while (window.pollEvent(event))


			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			

			case sf::Event::MouseButtonPressed:

				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (event.mouseButton.x > 850 && event.mouseButton.x < 950 && event.mouseButton.y > 700 && event.mouseButton.y < 775)
					{

						customSound koder;
						koder.StrToBit(test);
						koder.CRC(32);
						koder.message(22150);
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
						break;

					}
				}


			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Enter)
				{
					customSound koder;
					koder.StrToBit(test);
					koder.CRC(32);
					koder.sendBuffer(koder.Protokol);
					koder.message(22050);
					buffer.loadFromSamples(&koder._customSound[0], koder._customSound.size(), 1, 44100);
					sound.setBuffer(buffer);
					sound.play();
					koder.slet();

					// move sendte tekst
					textVector.insert(textVector.begin(), text);

					for (size_t i = 0; i < textVector.size(); i++)
					{
						textVector[i].move(0, -moveText);

					}

					// move rectangle
					for (size_t i = 0; i < textVector.size(); i++)
					{
						widthOfText = text.getLocalBounds().width;

						xyvec = textVector[i].getPosition();
						rectangleVec.insert(rectangleVec.begin(), sf::RectangleShape(sf::Vector2f(0, 0)));
						rectangleVec[i].setPosition(xyvec.x, xyvec.y + moveText);
						rectangleVec[i].setFillColor(sf::Color(128, 128, 128));
						rectangleVec[i].setSize(sf::Vector2f(widthOfText + 5, 35));


						for (size_t i = 0; i < rectangleVec.size(); i++)
						{

							rectangleVec[i].move(0, -moveText);


						}


					}



					test.clear();

					// receiver delen
					text2.setString(receive);
					widthOfReceive = text2.getLocalBounds().width;
					text2.setPosition(1000 - widthOfReceive - 50, 710 - moveText);

					textVector2.insert(textVector2.begin(), text2);

					for (size_t i = 1; i < textVector2.size(); i++)
					{
						textVector2[i].move(0, -moveText);

					}

					receive.clear();

					break;
				}


			case sf::Event::TextEntered:
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && (event.text.unicode != 13))
						test += (char)event.text.unicode;

					widthOfText = text.getLocalBounds().width + 50;
					sf::Vector2f vector;
					vector = rectangle.getPosition();
					float xRectangle = vector.x;
					float widthRect = xRectangle + rectangle.getSize().x;

					if (widthOfText + 40 >= widthRect)
					{
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
	window.draw(rectangleBesked);

	for (auto obj : rectangleVec)
	{
		window.draw(obj);
	}

	window.draw(text);
	window.draw(text2);

	for (auto obj : textVector)
	{
		window.draw(obj);
	}

	for (auto obj : textVector2)
	{
		window.draw(obj);
	}

	window.draw(send);
	window.display();
}



	return 0;
}







