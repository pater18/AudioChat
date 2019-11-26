#pragma once

#include <SFML/Audio.hpp>
#include "Timer.h"

#include <iostream>
#include <vector>
#include <cmath>

#define PI 3.14159265359


class SoundChunk
{
public:

	SoundChunk() { };
	SoundChunk(const std::vector<std::int16_t>& samples, std::size_t sampleCount)
		: m_samples(samples), m_sampleCount(sampleCount) { };
	void hanningWindow();
	std::vector<float> goertzelAlgorithm(int samplingFreq);
	int determineDtmfTwo(std::vector<float> freqComponents);
	int determineDTMF(std::vector<float> freqComponents);
	bool sortinrev(const std::pair<int, float>& a,
		const std::pair<int, float>& b) {
		return (a.second > b.second);
	};
	std::vector<float> goertzelForTest(std::vector<short> samples, int samplingFreq);

private:
	std::vector<std::int16_t> m_samples;
	std::size_t m_sampleCount;


	const std::vector<int> m_dtmfFreq = { 697, 770, 852, 941, 1209, 1336, 1477, 1633 };
	const std::vector< std::vector<int> > m_dtmfLookup {{0, 1, 2, 3},{ 4, 5 ,6 ,7 }, { 8, 9, 10, 11 }, { 12, 13 ,14 ,15 }};
	//std::vector<int> sendToDecoder;


	const double threshHold = 700, threshHoldMultiple = 1.3;

};