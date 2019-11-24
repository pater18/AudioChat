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
	void moveTextFunc(std::vector<sf::Text> sendTextVec, std::vector<sf::Text> receiveTextVec, sf::Text receiveText, std::vector<sf::Text> sendOrReceiveTextVec, sf::Text sendOrReceiveText);
	void displayUI(sf::RenderWindow &window);
	void send(sf::RenderWindow& window, sf::Event &event, CustomRecorder &recorder);
	void receive(CustomRecorder &recorder);
	//void defineSFMLobj();

	//sf::RectangleShape getRectangleTextBox(sf::RectangleShape &rectangleTextBox) { return m_rectangleTextBox = rectangleTextBox; };
	//sf::RectangleShape getRectangleSendBox(sf::RectangleShape &rectangleSendBox) { return m_rectangleSendBox = rectangleSendBox; };
	//std::vector<sf::Text> getSendTextVec(std::vector<sf::Text> &sendTextVec) { return m_sendTextVec = sendTextVec; };
	//std::vector<sf::Text> getReceiveTextVec(std::vector<sf::Text> &receiveTextVec) { return m_receiveTextVec = receiveTextVec; };
	//sf::Text getSendText(sf::Text &sendText) { return m_sendText = sendText; };
	//sf::Text getSendBox(sf::Text &sendBox) { return m_sendBox = sendBox; };
	//sf::Text getReceiveText(sf::Text &receiveText) { return m_receiveText = receiveText; };



private:
	//sf::RectangleShape m_rectangleTextBox;
	//sf::RectangleShape m_rectangleSendBox;
	//std::vector<sf::Text> m_sendTextVec;
	//std::vector<sf::Text> m_receiveTextVec;
	//sf::Text m_sendText;
	//sf::Text m_sendBox;
	//sf::Text m_receiveText;

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

