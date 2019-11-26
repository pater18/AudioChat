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
	recorder.stop();	
	customSound test;
	std::vector<sf::Int16> lyde{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	test.playSound(test.testAfLyd(44100 * g_sendeTid, lyde));*/
	


	Userinterface ui;
	ui.setUI();


	return 0;
}






