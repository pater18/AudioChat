#include "Userinterface.h"



//void Userinterface::makeSoundAck(std::vector<sf::Int16> _vecForAck) {
//	customSound koder;
//	koder.setBit(g_antalbit);
//	koder.playSound(koder.bitToAmplitudes(44100 * g_sendeTid, _vecForAck));
//}


void Userinterface::setUI() {

	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");

	std::vector<sf::Text> textVector;
	std::vector<sf::Text> textVector2;
	std::vector<sf::RectangleShape> rectangleVec;
	std::vector<sf::RectangleShape> rectangleVec2;
	sf::Vector2f xyvec;

	CustomRecorder recorder;

	sf::RectangleShape rectangle(sf::Vector2f(750, 75));
	rectangle.setFillColor(sf::Color(128, 128, 128));
	rectangle.setPosition(50, 700);


	sf::RectangleShape rectangleSend(sf::Vector2f(100, 75));
	rectangleSend.setFillColor(sf::Color(128, 128, 128));
	rectangleSend.setPosition(850, 700);

	sf::RectangleShape rectangleBesked(sf::Vector2f(100, 35));

	sf::Font font;
	font.loadFromFile("ariblk.ttf");


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

	std::string indtastedeBesked;

	recorder.start(g_samplingFreq);

	bool forventetSekNR = 0;

	while (window.isOpen())


	{
		if (recorder.getDecoder().getReceivedMessage())
		{
//////////////////////////////////////////////
			recorder.getDecoder().setReceivedMessageToFalse();

			std::string besked = recorder.getDecoder().decodeMessage();

			recorder.pause();
			int sekNr = recorder.getDecoder().getRenBitStreng()[7];
			int lastMessage = recorder.getDecoder().getRenBitStreng()[6];

			if ((sekNr == 0 || sekNr == 1) && lastMessage == 0)
			{
				if (forventetSekNR == sekNr)
				receive += besked;
				std::cout << "Hvad den enkelte pakke er i en streng: " << besked << std::endl;
				std::cout << receive << std::endl;

				Protokol modtagProtokol;
				modtagProtokol.modtagetProtokol(forventetSekNR, recorder.getDecoder().getRenBitStreng(),recorder);
				//recorder.getDecoder().setReceivedMessageToFalse();
				recorder.resume();

			}

			else if (lastMessage == 1 && sekNr == 1)
			{
				receive += besked;
				std::cout << "Hvad den enkelte pakke er i en streng: " << besked << std::endl;
				std::cout << receive << " " << "sidste" << std::endl;

				Protokol modtagProtokol;
				modtagProtokol.modtagetProtokol(forventetSekNR, recorder.getDecoder().getRenBitStreng(), recorder);

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
				indtastedeBesked.clear();
				recorder.resume();;
				std::cout << recorder.getDecoder().getReceivedMessage() << std::endl;
				
			}
		}

///////////////////////////////////////////

	//		sf::sleep(sf::milliseconds(1000));
			




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
						textVector.insert(textVector.begin(), text);

						for (size_t i = 0; i < textVector.size(); i++)
						{
							textVector[i].move(0, -moveText);

						}
						indtastedeBesked.clear();

					}
					break;
				}

			


			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Enter)
				{

					recorder.pause();

					Encoder encoder;
					Protokol protokolSend;
					protokolSend.sendProtokol(encoder.encoderMessage(indtastedeBesked), recorder);
					

					recorder.resume();;

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

					receive.clear();
					indtastedeBesked.clear();



					break;
				}

				if (event.key.code == sf::Keyboard::BackSpace)
				{
					if (indtastedeBesked.size() > 0)
					{
						indtastedeBesked.erase(indtastedeBesked.size() - 1, 1);
						text.setString(indtastedeBesked);
					}

					break;
				}

			case sf::Event::TextEntered:
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128 && (event.text.unicode != 13) && (event.text.unicode != 8))
						indtastedeBesked += (char)event.text.unicode;

					widthOfText = text.getLocalBounds().width + 50;
					sf::Vector2f vector;
					vector = rectangle.getPosition();
					float xRectangle = vector.x;
					float widthRect = xRectangle + rectangle.getSize().x;

					if (widthOfText + 40 >= widthRect)
					{
						indtastedeBesked += "\n";
						widthOfText = 50;

					}

					text.setString(indtastedeBesked);


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