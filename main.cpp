#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Sound.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::SoundBuffer buffer;
	std::vector<sf::Int16> samples;

	for (int i = 0; i < 44100; i++)
	{
		samples.push_back(sound::SineWave(i, 440, 0.9));
	}

	buffer.loadFromSamples(&samples[0], samples.size(), 1, 441000);

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}