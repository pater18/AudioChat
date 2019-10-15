#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "StringToBit.h"
#include "Sound.h"
#include "Tone.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string> 
#include <thread>
#include <chrono>





int main()
{
	//std::vector<int> test_a_streng;				//En vektor der skal indeholde den binære sekvens for en streng
	//StrToBit(test_a_streng, "Hello World");		//Beskeden der skal sendes og den vektor den skal ligge i som 1 og 0. 


	//sf::SoundBuffer buffer;
	//sf::Sound sound;
	//std::vector<sf::Int16> test;				

	//message(test, 11025, test_a_streng);		//Tager besked vektoren med 1 og 0 og lægger det i en ny vektor, som kan læses af SFML. Hver tone bliver sendt i 1 sekund = 44100. 


	//buffer.loadFromSamples(&test[0], test.size(), 1, 44100);
	//sound.setBuffer(buffer);
	//sound.play();


	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

	
	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (!sf::SoundBufferRecorder::isAvailable())
		{
			std::cout << "Error";
		}

		sf::SoundBufferRecorder recorder;
		recorder.start();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		const sf::SoundBuffer& buffer = recorder.getBuffer();
		recorder.stop();



		const sf::Int16* samples = buffer.getSamples();
		std::size_t count = buffer.getSampleCount();

		for (std::size_t i = 30000; i < 30500; i++)
			std::cout << samples[i] << " ";
		
		break;
	}

	return 0;
}




