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

void goertzelTestFunction()
{
	customSound soundTest;

	std::ofstream outputRecording;
	outputRecording.open("Recording.txt");
	std::vector<short> soundVect;

	int samplingDivisor = 4;

	for (std::size_t i = 0; i < 10000; i = i + samplingDivisor)
	{
		soundVect.push_back(soundTest.Sinewave(i, 697, 1633, 0.2));
		outputRecording << soundVect[i / samplingDivisor] << std::endl;
	}
	std::cout << soundVect.size() << std::endl;
	outputRecording.close();

	SoundChunk soundChunk;
	std::vector<float> goertzelResult;
	goertzelResult = soundChunk.goertzelForTest(soundVect, 44100 / samplingDivisor);
	for (std::size_t i = 0; i < goertzelResult.size(); i++)
	{
		std::cout << goertzelResult[i] << " ";
	}

}

int main()
{

	customSound koder;

	koder.StrToBit("");
	koder.message(44100*5);

	sf::SoundBuffer buffer;
	sf::Sound sound;


	buffer.loadFromSamples(&koder._customSound[0], koder._customSound.size(), 1, 44100);
	sound.setBuffer(buffer);
	sound.play();

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		//goertzelTestFunction();
		CustomRecorder recorder;

		recorder.start(10000);
		std::this_thread::sleep_for(std::chrono::seconds(100));
		recorder.stop();


		std::this_thread::sleep_for(std::chrono::seconds(100));

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}







