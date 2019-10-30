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
	
	m_curDTMF = currentSoundChunk.determineDTMF(goertzelResult);
	int syncGoertzel = syncDTMF();
	if (syncGoertzel != -1) {
		std::cout << std::endl;
		std::cout << syncGoertzel << std::endl;
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

int CustomRecorder::syncDTMF()
{
	if (m_curDTMF == -1)
		return -1;
	if (m_curDTMF == m_lastDTMF)
	{
		if (m_secondDetection == true) 
		{
			duration = (std::clock() - startClock) / (double)CLOCKS_PER_SEC;
			if (duration > 1)
			{
				startClock = std::clock();
				return m_curDTMF;
			}
			return -1;
		}
		m_secondDetection = true;
		startClock = std::clock();
		return m_curDTMF;
	}
	m_lastDTMF = m_curDTMF;
	m_secondDetection = false;
	return -1;
}
