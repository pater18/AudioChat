#pragma once
#include <SFML/Audio.hpp>
#include "SoundChunk.h"

#include <iostream>
#include <vector>
#include <fstream>

class CustomRecorder : public sf::SoundRecorder
{
public:
	bool onStart();
	bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount);
	void onStop();
	void setSaveRecording() { m_saveRecording = true;  };
	void saveRecording(const sf::Int16* samples, std::size_t sampleCount);
private:
	sf::Int16 m_samples;
	bool m_saveRecording = false;
};