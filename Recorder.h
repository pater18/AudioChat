#pragma once
#include <SFML/Audio.hpp>

class Recorder
{
public: 
	Recorder();




private:
	sf::SoundBufferRecorder recorder;
	sf::SoundBuffer recBuffer;
	sf::Sound recSound;
};