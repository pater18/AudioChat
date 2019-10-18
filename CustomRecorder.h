#pragma once

#include <SFML/Audio.hpp>

#include <iostream>

class CustomRecorder : public sf::SoundRecorder
{
public:
	CustomRecorder() { };
	~CustomRecorder() { stop(); }
	bool onStart();
	bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount);
	void onStop() { };
private:

};