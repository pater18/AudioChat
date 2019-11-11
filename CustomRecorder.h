#pragma once
#include <SFML/Audio.hpp>
#include "SoundChunk.h"
#include "Decoder.h"

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
	void saveGoertzel(std::vector<float> goertzelData);
	int syncDTMF();
<<<<<<< Updated upstream
	void updateRingBuffer(int DTMFTone);
=======
	void setCurDTMF(int curDTMF) { m_curDTMF = curDTMF; };
	Decoder getDecoder() { return m_decoder; };
>>>>>>> Stashed changes

	std::clock_t startClock;
private:
	sf::Int16 m_samples;
	int m_processingCycles = 0;
	const int m_processingInterval = 30;
	bool m_saveRecording = false;
	std::vector<int> m_ringBuffer;
	int m_ringBrufferPointer = 0;
	int m_lastDTMF = -1, m_curDTMF = -1;
	double duration;
	bool m_secondDetection = false;
	const std::vector<int> flag = { 15,0 },
		escCharacter = { 14,0 };
	std::ofstream goertzel;
	Decoder m_decoder;
};