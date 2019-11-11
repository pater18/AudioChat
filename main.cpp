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
	customSound koder;

	koder.StrToBit("");
	koder.message(44100 * 10);

	sf::SoundBuffer buffer;
	sf::Sound sound;

	buffer.loadFromSamples(&koder._customSound[0], koder._customSound.size(), 1, 44100);
	sound.setBuffer(buffer);
	sound.play();
	//sound.play();

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		CustomRecorder recorder;

		recorder.start(10000);
		std::this_thread::sleep_for(std::chrono::seconds(7));
		recorder.stop();


		std::this_thread::sleep_for(std::chrono::seconds(100));

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}







