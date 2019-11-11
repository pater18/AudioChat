#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Encoder.h"
#include "Sound.h"
#include "CustomRecorder.h"
#include "Decoder.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string> 
#include <thread>
#include <chrono>

int main()
{


	sf::Event event;

	//-----------------------------------------------------------------------------------------------------------------------
	//Laver en besked der kan sendes
	customSound koder;
	koder.setBit(32);
	koder.StrToBit("hej med d");
	
	
	
	koder.opdel();
	koder.CRC();
	koder.message(44100);					//Tager besked vektoren med 1 og 0 og l�gger det i en ny vektor, som kan l�ses af SFML. Hver tone bliver sendt i 1 sekund = 44100. 
	koder.sletFrame();
	koder.slet(); 

	

	return 0;
}






