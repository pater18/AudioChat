#pragma once
#include <SFML/Audio.hpp>
#include "SoundChunk.h"

#include <thread>
#include <chrono>
#include <cstdio>
#include <ctime>

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
	int syncDTMF();

	std::clock_t startClock;
private:
	sf::Int16 m_samples;
	bool m_saveRecording = false;
	int m_lastDTMF = -1, m_curDTMF = -1;
	double duration;
	bool m_secondDetection = false;
};