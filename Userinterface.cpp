#include "Userinterface.h"

void Userinterface::makeSoundAck(std::vector<sf::Int16> _vecForAck) {
	customSound koder;
	koder.setBit(32);
	koder.playSound(koder.bitToAmplitudes(44100 / 5, _vecForAck));
}

void Userinterface::moveTextFunc(std::vector<sf::Text> sendTextVec, std::vector<sf::Text> receiveTextVec, std::vector<sf::Text> sendOrReceiveTextVec, sf::Text sendOrReceiveText)
{
	int moveText = 80;

	sendOrReceiveTextVec.insert(sendOrReceiveTextVec.begin(), sendOrReceiveText);

	for (size_t i = 0; i < sendTextVec.size(); i++)
	{

		sendTextVec[i].move(0, -moveText);

	}

	for (size_t i = 0; i < receiveTextVec.size(); i++)
	{
		receiveTextVec[i].move(0, -moveText);

	}

}

void Userinterface::displayUI(sf::RenderWindow &window)
{
	window.clear(sf::Color::White);
	window.draw(rectangleTextBox);
	window.draw(rectangleSendBox);

	window.draw(sendBox);
	window.draw(sendText);
	window.draw(receiveText);

	for (auto obj : sendTextVec)
	{
		window.draw(obj);
	}

	for (auto obj : receiveTextVec)
	{
		window.draw(obj);
	}

	window.display();
}


void Userinterface::setupUI()
{
	rectangleTextBox.setSize(sf::Vector2f(750, 75));
	rectangleTextBox.setFillColor(sf::Color(128, 128, 128));
	rectangleTextBox.setPosition(50, 700);

	rectangleSendBox.setSize(sf::Vector2f(100, 75));
	rectangleSendBox.setFillColor(sf::Color(128, 128, 128));
	rectangleSendBox.setPosition(850, 700);

	sf::Font font;
	font.loadFromFile("blue.ttf");

	sendText.setFont(font);
	sendText.setCharacterSize(20);
	sendText.setFillColor(sf::Color::Black);
	sendText.setPosition(60, 710);

	sendBox.setFont(font);
	sendBox.setString("Send");
	sendBox.setCharacterSize(20);
	sendBox.setFillColor(sf::Color::Black);
	sendBox.setPosition(880, 725);

	receiveText.setFont(font);
	receiveText.setCharacterSize(20);
	receiveText.setFillColor(sf::Color::Black);
	
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Userinterface");

	CustomRecorder recorder;
	recorder.start(12000);

	while (window.isOpen())
	{
		receive(recorder);

		sf::Event event;

		while (window.pollEvent(event))
		{
			send(window, event, recorder);
		}

		displayUI(window);
	}
}

void Userinterface::receive(CustomRecorder &recorder)
{

	if (recorder.getDecoder().getReceivedMessage())
	{
		// receiver delen
		receiveMessage = recorder.getDecoder().decodeMessage();

		Protokol modtagProtokol;
		modtagProtokol.modtagetProtokol(forventetSekNR, recorder.getDecoder().getRenBitStreng());

		//std::vector<sf::Int16> sendAck = indtastedeBeskedprot.modtagetProtokol(recorder.getDecoder().getVecAck());

		sf::sleep(sf::milliseconds(1000));
		//recorder.stop();
		//makeSoundAck(sendAck);

		std::cout << receiveMessage << std::endl;
		receiveText.setString(receiveMessage);

		widthOfReceive = receiveText.getLocalBounds().width;
		receiveText.setPosition(1000 - widthOfReceive - 50, 710 - moveText);

		// move sendte tekst
		moveTextFunc(sendTextVec, receiveTextVec, receiveTextVec, receiveText);

		std::cout << "Input if " << std::endl;
		receiveMessage.clear();
		indtastedeBesked.clear();
		recorder.start(12000);
		std::cout << recorder.getDecoder().getReceivedMessage() << std::endl;
		recorder.getDecoder().setReceivedMessageToFalse();
	}
}

void Userinterface::send(sf::RenderWindow &window, sf::Event &event, CustomRecorder &recorder)
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

				moveTextFunc(sendTextVec, receiveTextVec, sendTextVec, sendText);

				indtastedeBesked.clear();

			}
			break;
		}

	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Enter)
		{

			recorder.stop();

			Encoder encoder;
			Protokol protokolSend;
			protokolSend.sendProtokol(encoder.encoderMessage(indtastedeBesked));

			recorder.start(12000);

			// move sendte tekst
			widthOfReceive = receiveText.getLocalBounds().width;
			receiveText.setPosition(1000 - widthOfReceive - 50, 710 - moveText);
			moveTextFunc(sendTextVec, receiveTextVec, sendTextVec, sendText);

			receiveMessage.clear();
			indtastedeBesked.clear();

			break;
		}

		if (event.key.code == sf::Keyboard::BackSpace)
		{
			if (indtastedeBesked.size() > 0)
			{
				indtastedeBesked.erase(indtastedeBesked.size() - 1, 1);
				sendText.setString(indtastedeBesked);
			}

			break;
		}

	case sf::Event::TextEntered:
		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode < 128 && (event.text.unicode != 13) && (event.text.unicode != 8))
			{
				indtastedeBesked += (char)event.text.unicode;
			}
			sendText.setString(indtastedeBesked);

			break;
		}
	}
}
