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
	/*CustomRecorder recorder;
	recorder.start(g_samplingFreq);
	sf::sleep(sf::seconds(g_sendeTid * 16 + 3));
	recorder.stop();*/
	customSound test;
	std::vector<sf::Int16> lyde{ 0 };
	/*test.playSound(test.testAfLyd(44100 * g_sendeTid, lyde));*/
	
	auto test2 = test.testAfLyd(44100, lyde);

	std::vector<sf::Int16> test3(test2.begin() + 20000, test2.begin() + 20205);

	SoundChunk testlyd{ test3,205 };
	testlyd.hanningWindow();
	auto endelig =testlyd.goertzelAlgorithm(12000);

	for (size_t i = 0; i < endelig.size(); i++)
	{
		std::cout << endelig[i] << " ";
	}



	//Userinterface ui;
	//ui.setUI();


	return 0;
}






