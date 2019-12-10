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
	void setUI();

	void rectangle();
	sf::RectangleShape getRectangle() { return m_rectangle; };
	void text(sf::Font& font);
	sf::Text getText() { return m_text; };

	void setupUI(sf::Font &font);

private:
	double widthOfText = 0;
	int moveText = 80;

	double widthOfReceive;
	std::string receive;
	
	sf::RectangleShape m_rectangle;
	sf::Text m_text;
	
};

