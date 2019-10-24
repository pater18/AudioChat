#pragma once

#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>
#include <cmath>




class SoundChunk
{
public:
	SoundChunk();
	SoundChunk(const sf::Int16*  samples, std::size_t sampleCount)
		: m_samples(samples), m_sampleCount(sampleCount) { };
	std::vector<float> goertzelAlgorithm(int samplingFreq);
	int determineDTMF(std::vector<float> freqComponents);
	bool sortinrev(const std::pair<int, float>& a,
		const std::pair<int, float>& b) { return (a.second > b.second); };
private:
	const sf::Int16* m_samples;
	std::size_t m_sampleCount;
	const std::vector<int> m_dtmfFreq = { 697, 770, 852, 941, 1209, 1336, 1477, 1633 };
	const std::vector< std::vector<int> > m_dtmfLookup {{0, 1, 2, 3},{ 4,5,6,7 }, { 8,9,10,11 }, { 12,13,14,15 }};
protected:
	std::vector<int> sendToDecoder;
};
