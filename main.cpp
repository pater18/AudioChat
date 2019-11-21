#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Encoder.h"
#include "Sound.h"
#include "CustomRecorder.h"
#include "Decoder.h"
#include "Protokol.h"
#include "Userinterface.h"
#include "Timer.h"


#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string> 
#include <thread>
#include <chrono>


	//int moveText = 80;
	//double widthOfReceive;
	//std::string receiveMessage;
	//std::string indtastedeBesked;
	//bool forventetSekNR = 0;

	//sf::RectangleShape rectangleTextBox;
	//sf::RectangleShape rectangleSendBox;
	//std::vector<sf::Text> sendTextVec;
	//std::vector<sf::Text> receiveTextVec;
	//sf::Text sendText;
	//sf::Text sendBox;
	//sf::Text receiveText;

int main()
{


	Userinterface ui;

	ui.UI();

	//sf::RenderWindow window(sf::VideoMode(1000, 800), "Userinterface");

	//CustomRecorder recorder;
	//recorder.start(12000);

	//while (window.isOpen())
	//{
	//	ui.receive(recorder);

	//	sf::Event event;

	//	while (window.pollEvent(event))
	//	{
	//		ui.send(window, event, recorder);
	//	}

	//	ui.displayUI(window);
	//}


	return 0;
}






