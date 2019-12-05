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

private:
	double widthOfText = 0;
	int moveText = 80;

	double widthOfReceive;
	std::string receive;
	std::string indtastedeBesked;
	bool forventetSekNR = 0;
	
};

