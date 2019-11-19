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
	
	CustomRecorder recorder;
	recorder.start(12000);
	std::this_thread::sleep_for(std::chrono::seconds(10));
	recorder.stop();
	std::this_thread::sleep_for(std::chrono::seconds(10));

	setUI();

	return 0;
}






