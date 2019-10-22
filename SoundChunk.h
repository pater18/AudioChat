#pragma once

#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>
#include <cmath>



class SoundChunk
{
public:
	SoundChunk(const sf::Int16*  samples, std::size_t sampleCount)
		: m_samples(samples), m_sampleCount(sampleCount) { };
	std::vector<float> goertzelAlgorithm(int samplingFreq);
private:
	const sf::Int16* m_samples;
	std::size_t m_sampleCount;
	std::vector<int> m_DtmfFreq = { 697, 770, 852, 941, 1209, 1336, 1477, 1633 };
};
