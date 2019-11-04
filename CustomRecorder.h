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
	void updateRingBuffer(int DTMFTone);

	std::clock_t startClock;
private:
	sf::Int16 m_samples;
	bool m_saveRecording = false;
	std::vector<int> m_ringBuffer;
	int m_ringBrufferPointer = 0;
	int m_lastDTMF = -1, m_curDTMF = -1;
	double duration;
	bool m_secondDetection = false;
	const std::vector<int> flag1 = { 15,0 }, flag2 = { 0,15 },
		escCharacter = { 2,3,2,3,2,3,2,3 };
};