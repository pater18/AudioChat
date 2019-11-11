#include "CustomRecorder.h"

bool CustomRecorder::onStart()
{
	std::cout << "Recording started with " << this->getSampleRate() << " sampling freq" << std::endl;
	setProcessingInterval(sf::milliseconds(m_processingInterval));
	goertzel.open("GoertzelData.txt");
	recording.open("Recording.txt");
	goertzel << "Hz697" << " " << "Hz770" << " ";
	goertzel << "Hz852" << " " << "Hz941" << " ";
	goertzel << "Hz1209" << " " << "Hz1336" << " ";
	goertzel << "Hz1477" << " " << "Hz1633" << std::endl;
	return true;
}

bool CustomRecorder::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
{
	m_processingCycles++;
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
		m_decoder.setDTMFTone(syncGoertzel);
	}


	if (m_processingCycles > 3000 / m_processingInterval)
	{
		saveGoertzel(goertzelResult);
		saveRecording(samples, sampleCount); 
	}
		
	return true;
}

void CustomRecorder::onStop()
{
	//If saveRecording - close
	goertzel.close();
	recording.close();
	std::cout << std::endl << "Recording stopped" << std::endl;
}

void CustomRecorder::saveRecording(const sf::Int16* samples, std::size_t sampleCount)
{
	for (std::size_t i = 0; i < sampleCount; i++)
		recording << samples[i] << std::endl;
}

void CustomRecorder::saveGoertzel(std::vector<float> goertzelData)
{
	for (std::size_t i = 0; i < goertzelData.size(); i++)
	{
		goertzel << goertzelData[i] << " ";
	}
	goertzel << std::endl;
	
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
			if (duration > 0.2)
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

