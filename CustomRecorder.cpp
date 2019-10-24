#include "CustomRecorder.h"

bool CustomRecorder::onStart()
{
	setProcessingInterval(sf::milliseconds(10));
	return true;
}

bool CustomRecorder::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
{
	SoundChunk currentSoundChunk(samples, sampleCount);
	//for (std::size_t i = 0; i < 8; i++)
	//{
	//	std::cout << currentSoundChunk.goertzelAlgorithm(this->getSampleRate())[i] << " ";
	//}
	std::vector<float> goertzelResult = currentSoundChunk.goertzelAlgorithm(this->getSampleRate());
	std::cout << currentSoundChunk.determineDTMF(goertzelResult) << " ";

	if (m_saveRecording == true)
	{
		saveRecording(samples, sampleCount);
	}

	return true;
}

void CustomRecorder::onStop()
{
	//If saveRecording - close
}

void CustomRecorder::saveRecording(const sf::Int16* samples, std::size_t sampleCount)
{
	std::ofstream recording;
	recording.open("Recording.txt");
	for (std::size_t i = 0; i < sampleCount; i++)
		recording << samples[i] << std::endl;
}
