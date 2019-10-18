#include "CustomRecorder.h"

bool CustomRecorder::onStart()
{
	setProcessingInterval(sf::milliseconds(20));
	return true;
}

bool CustomRecorder::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
{
	for (std::size_t i=0; i < sampleCount; i++)
		std::cout << samples[i] << " ";
	return true;
}
