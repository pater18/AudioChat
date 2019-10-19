#pragma once
#include <SFML/Audio.hpp>
#include "SoundChunk.h"

#include <iostream>
#include <vector>
#include <fstream>

class CustomRecorder : public sf::SoundRecorder
{
public:
	CustomRecorder() { };
	~CustomRecorder() { stop(); }
	bool onStart();
	bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount);
	void onStop();
	void setSaveRecording() { saveRecording = true;  };

private:
	sf::Int16 m_samples;
	bool saveRecording = false;
};