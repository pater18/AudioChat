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
	void makeSoundAck(std::vector<sf::Int16> _vecForAck);
	void initUI();
	void setupUI();
	void moveTextFunc(std::vector<sf::Text> sendTextVec, std::vector<sf::Text> receiveTextVec, std::vector<sf::Text> sendOrReceiveTextVec, sf::Text sendOrReceiveText);
	void displayUI(sf::RenderWindow &window);
	void UI();
	void send(sf::RenderWindow& window, sf::Event &event, CustomRecorder &recorder);
	void receive(CustomRecorder &recorder);

private:
	sf::RectangleShape rectangleTextBox;
	sf::RectangleShape rectangleSendBox;
	std::vector<sf::Text> sendTextVec;
	std::vector<sf::Text> receiveTextVec;
	sf::Text sendText;
	sf::Text sendBox;
	sf::Text receiveText;

	int moveText = 80;
	double widthOfReceive;
	std::string receiveMessage;
	std::string indtastedeBesked;
	bool forventetSekNR = 0;

};

