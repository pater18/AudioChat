#pragma once
#include <SFML/Audio.hpp>
#include "SoundChunk.h"

#include <iostream>
#include <vector>

class CustomRecorder : public sf::SoundRecorder
{
public:
	CustomRecorder() { };
	~CustomRecorder() { stop(); }
	bool onStart();
	bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount);
	void onStop() { };
private:
	sf::Int16 m_samples;

};