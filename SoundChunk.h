#pragma once

#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>

class SoundChunk
{
public:
	SoundChunk(const sf::Int16*  samples)
		: m_samples(samples) { };
	void goertzelAlgorithm() { std::cout << m_samples[1]; };
private:
	const sf::Int16* m_samples;
};
