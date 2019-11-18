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




int main()
{
	CustomRecorder record;
	record.start(12000);
	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	record.stop();

	/*customSound lyd;

	sf::Sound sound;
	sf::SoundBuffer buffer;

	std::vector<sf::Int16> toner = { 0, 1, 2, 3 };
	std::vector<sf::Int16> lyde = lyd.testAfLyd(44100, toner);


	buffer.loadFromSamples(&lyde[0], lyde.size(), 1, 44100);
	sound.setBuffer(buffer);
	sound.play();

	std::this_thread::sleep_for(std::chrono::milliseconds(20000));*/
	
	//setUI();

	return 0;
}






