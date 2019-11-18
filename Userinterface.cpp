#include "CustomRecorder.h"
#include "Decoder.h"
#include "Userinterface.h"
#include "Protokol.h"

sf::SoundBuffer buffer;
sf::Sound sound;
std::string test;
Protokol testprot;

void makeSound() {

	customSound koder;
	std::cout << test << std::endl;
	koder.setBit(32);
	koder.StrToBit(test);
	koder.CRC();
	koder.sendBuffer(koder.insertESC);
	koder.slet();
	testprot.sendProtokol(koder.vecSendBuffer);
//	koder.message(44100/4);
//	buffer.loadFromSamples(&koder._customSound[0], koder._customSound.size(), 1, 44100);
//	sound.setBuffer(buffer);
//	sound.play();
//	koder.slet();
}

void makeSoundAck(std::vector<sf::Int16> _vecForAck) {
	customSound koder;
	std::cout << test << std::endl;
	koder.setBit(32);
	koder.message(44100/4, _vecForAck);
	buffer.loadFromSamples(&koder._customSound[0], koder._customSound.size(), 1, 44100);
	sound.setBuffer(buffer);
	sound.play();
	koder.slet();
}

void setUI() {

	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");

	std::vector<sf::Text> textVector;
	std::vector<sf::Text> textVector2;
	std::vector<sf::RectangleShape> rectangleVec;
	std::vector<sf::RectangleShape> rectangleVec2;
	sf::Vector2f xyvec;


	double widthOfText = 0;
	int moveText = 80;

	double widthOfReceive;
	std::string receive;
	CustomRecorder recorder;
	
	sf::RectangleShape rectangle(sf::Vector2f(750, 75));
	rectangle.setFillColor(sf::Color(128, 128, 128));
	rectangle.setPosition(50, 700);


	sf::RectangleShape rectangleSend(sf::Vector2f(100, 75));
	rectangleSend.setFillColor(sf::Color(128, 128, 128));
	rectangleSend.setPosition(850, 700);
 
	sf::RectangleShape rectangleBesked(sf::Vector2f(100, 35));

	sf::Font font;
	font.loadFromFile("blue.ttf");


	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Black);
	text.setPosition(60, 710);


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

	recorder.start(10000);

	while (window.isOpen())
	{
		if (recorder.getDecoder().getReceivedMessage())
		{
			recorder.stop();
			// receiver delen
			receive = recorder.getDecoder().getBesked();


			std::vector<sf::Int16> sendAck = testprot.modtagetProtokol(recorder.getDecoder().getVecAck());



			for (size_t i = 0; i < sendAck.size(); i++)
			{
				std::cout << sendAck[i] << " ";
			}

			std::cout << std::endl; 

			//makeSoundAck(sendAck);

			std::cout << receive << std::endl;
			text2.setString(receive);
			widthOfReceive = text2.getLocalBounds().width;
			text2.setPosition(1000 - widthOfReceive - 50, 710 - moveText);
			


			// move sendte tekst
			for (size_t i = 0; i < textVector.size(); i++)
			{

				textVector[i].move(0, -moveText);

			}

			textVector2.insert(textVector2.begin(), text2);

			for (size_t i = 1; i < textVector2.size(); i++)
			{
				textVector2[i].move(0, -moveText);

			}
			std::cout << "Input if " << std::endl;
			receive.clear();
			test.clear();
			recorder.start(10000);
			std::cout << recorder.getDecoder().getReceivedMessage() << std::endl;
			recorder.getDecoder().setReceivedMessageToFalse();
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
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

						makeSound();

						textVector.insert(textVector.begin(), text);

						for (size_t i = 0; i < textVector.size(); i++)
						{
							textVector[i].move(0, -moveText);

						}

						test.clear();


					}
					break;
				}

			


			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Enter)
				{
					recorder.stop();
					makeSound();

					while (sound.getStatus() != 0)
					{
					}
					recorder.start(10000);

					receive.clear();
					
					// move sendte tekst
					widthOfReceive = text2.getLocalBounds().width;
					text2.setPosition(1000 - widthOfReceive - 50, 710 - moveText);

					textVector.insert(textVector.begin(), text);
					for (size_t i = 0; i < textVector.size(); i++)
					{
						textVector[i].move(0, -moveText);

					}

					for (size_t i = 0; i < textVector2.size(); i++)
					{
						textVector2[i].move(0, -moveText);

					}

					// move rectangle
					//for (size_t i = 0; i < textVector.size(); i++)
					//{
					//	widthOfText = text.getLocalBounds().width;

					//	xyvec = textVector[i].getPosition();
					//	rectangleVec.insert(rectangleVec.begin(), sf::RectangleShape(sf::Vector2f(0, 0)));
					//	rectangleVec[i].setPosition(xyvec.x, xyvec.y + moveText);
					//	rectangleVec[i].setFillColor(sf::Color(128, 128, 128));
					//	rectangleVec[i].setSize(sf::Vector2f(widthOfText + 5, 35));


					//	for (size_t i = 0; i < rectangleVec.size(); i++)
					//	{

					//		rectangleVec[i].move(0, -moveText);


					//	}


					//}


					receive.clear();
					test.clear();



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
		}

		window.clear(sf::Color::White);
		window.draw(rectangle);
		window.draw(rectangleSend);
		window.draw(rectangleBesked);

		for (auto obj : rectangleVec)
		{
			window.draw(obj);
		}
		//

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


}