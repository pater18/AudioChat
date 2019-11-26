#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "CustomRecorder.h"
#include "Decoder.h"
#include "Protokol.h"
#include "Timer.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string> 
#include <thread>
#include <chrono>

class Userinterface{

public:
	void makeSound();
	void setupUI();
	void moveTextFunc(std::vector<sf::Text> sendTextVec, std::vector<sf::Text> receiveTextVec, sf::Text receiveText, std::vector<sf::Text> sendOrReceiveTextVec, sf::Text sendOrReceiveText);
	void displayUI(sf::RenderWindow& window);
	void send(sf::RenderWindow& window, sf::Event& event, CustomRecorder& recorder);
	void receive(CustomRecorder& recorder);



private:
	sf::RectangleShape rectangleTextBox;
	sf::RectangleShape rectangleSendBox;
	std::vector<sf::Text> sendTextVec;
	std::vector<sf::Text> receiveTextVec;
	sf::Text sendText;
	sf::Text sendBox;
	sf::Text receiveText;

	std::string receiveMessage;
	std::string indtastedeBesked;
	bool forventetSekNR = 0;
	
};

