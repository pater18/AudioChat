#include "CustomRecorder.h"

bool CustomRecorder::onStart()
{
	setProcessingInterval(sf::milliseconds(10));
	return true;
}

bool CustomRecorder::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
{
	SoundChunk currentSoundChunk(samples, sampleCount);
	currentSoundChunk.goertzelAlgorithm();

	if (saveRecording = true)
	{
		std::ofstream recording;
		recording.open("Recording.txt");
		for (std::size_t i = 0; i < sampleCount; i++)
			recording << samples[i] << std::endl;
	}

	return true;
}

void CustomRecorder::onStop()
{
	//stop recording
}
