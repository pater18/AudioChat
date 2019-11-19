#pragma once
#include <SFML/Audio.hpp>
#include "SoundChunk.h"
#include "Decoder.h"
#include "Timer.h"

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
	~CustomRecorder();
	bool onStart();
	bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount);
	void onStop();

	void saveGoertzelMatrixToFile();
	int syncDTMF();

	Decoder& getDecoder() { return m_decoder; };
	void setCurDTMF(int curDTMF) { m_curDTMF = curDTMF; };

	std::clock_t startClock;
private:
	sf::Int16 m_samples;
	int m_processingCycles = 0;

	const int m_processingInterval = 20;
	double sendingTime = 0.5;


	std::vector<std::vector <float> > m_goertzelDataMatrix;
	bool m_startSavingGoertzel = false;

	int m_lastDTMF = -1, m_curDTMF = -1;
	double duration;
	bool m_secondDetection = false;
;
	Decoder m_decoder;
};

