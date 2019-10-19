#pragma once

#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>

class SoundChunk
{
public:
	SoundChunk(const sf::Int16*  samples, std::size_t sampleCount)
		: m_samples(samples), m_sampleCount(sampleCount) { };
	void goertzelAlgorithm();
private:
	const sf::Int16* m_samples;
	std::size_t m_sampleCount;
};
