#include "CustomRecorder.h"

bool CustomRecorder::onStart()
{
	setProcessingInterval(sf::milliseconds(2));
	return true;
}

bool CustomRecorder::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
{
	SoundChunk currentSoundChunk(samples, sampleCount);
	currentSoundChunk.goertzelAlgorithm();

	return true;
}
