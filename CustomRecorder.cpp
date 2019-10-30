#include "CustomRecorder.h"

bool CustomRecorder::onStart()
{
	std::cout << "Recording started" << std::endl;
	setProcessingInterval(sf::milliseconds(30));
	return true;
}

bool CustomRecorder::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
{
	SoundChunk currentSoundChunk(samples, sampleCount);
	std::vector<float> goertzelResult = currentSoundChunk.goertzelAlgorithm(this->getSampleRate());
	//for (std::size_t i = 0; i < goertzelResult.size(); i++)
	//{
	//	std::cout << goertzelResult[i] << " ";
	//}

	//std::cout << std::endl;
	
	int rawGoertzel = currentSoundChunk.determineDTMF(goertzelResult);
	int syncGoertzel = currentSoundChunk.synchroniseDTMF(rawGoertzel, m_lastDTMF);
	if (syncGoertzel != -1) {
		std::cout << std::endl;
		std::cout << syncGoertzel << std::endl;
		m_lastDTMF = syncGoertzel;
	}
 
	
	if (m_saveRecording == true)
	{
		saveRecording(samples, sampleCount);
	}

	return true;
}

void CustomRecorder::onStop()
{
	//If saveRecording - close
	std::cout << std::endl << "Recording stopped" << std::endl;
}

void CustomRecorder::saveRecording(const sf::Int16* samples, std::size_t sampleCount)
{
	std::ofstream recording;
	recording.open("Recording.txt");
	for (std::size_t i = 0; i < sampleCount; i++)
		recording << samples[i] << std::endl;
}
