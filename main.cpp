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
	customSound soundcustom;
	std::vector<sf::Int16> bitStreng = { 1,1,1,1,0,0,0,0 };

	auto vectorOfAmplitudes = soundcustom.bitToAmplitudes(44100, bitStreng);
	soundcustom.playSound(vectorOfAmplitudes);

	std::cout << "hej";

;
	std::this_thread::sleep_for(std::chrono::seconds(100));
	
	setUI();

	return 0;
}






