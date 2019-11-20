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
	customSound customSound;
	std::vector<sf::Int16> lyden = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,15 };
	customSound.playSound(customSound.testAfLyd(44100 * 1, lyden));
	
	

	setUI();

	return 0;
}






