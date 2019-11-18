#include "CustomRecorder.h"

CustomRecorder::~CustomRecorder()
{
	this->stop();
}

bool CustomRecorder::onStart()
{
	std::cout << "Recording started with " << this->getSampleRate() << " sampling freq" << std::endl;
	setProcessingInterval(sf::milliseconds(m_processingInterval));
	return true;
}


bool CustomRecorder::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
{
  
	if (sampleCount > 205)
	{
		m_processingCycles++;


		std::vector<std::int16_t> samplesForProcessing;

		for (std::size_t i = 0; i < 205; i++)
			samplesForProcessing.push_back(samples[i]);

		SoundChunk currentSoundChunk(samplesForProcessing, samplesForProcessing.size());
		currentSoundChunk.hanningWindow();
		std::vector<float> goertzelResult = currentSoundChunk.goertzelAlgorithm(this->getSampleRate());
		/*if (m_startSavingGoertzel == true)*/
		m_goertzelDataMatrix.push_back(goertzelResult);

		m_curDTMF = currentSoundChunk.determineDtmfTwo(goertzelResult);
		int syncGoertzel = syncDTMF();

		if (syncGoertzel != -1) {
			m_decoder.setDTMFTone(syncGoertzel);
			m_startSavingGoertzel = true;
		}


		if (m_processingCycles > 1000 / m_processingInterval)
		{
			//saveGoertzel(goertzelResult);
			//saveRecording(samples, sampleCount); 
		}
	}
	else
		std::cout << "Ikke samples nok" << std::endl; 


	return true;
}

void CustomRecorder::onStop()
{
	saveGoertzelMatrixToFile();
	std::cout << std::endl << "Recording stopped" << std::endl;
}

void CustomRecorder::saveGoertzelMatrixToFile()
{
	std::ofstream goertzel;
	goertzel.open("Goertzel.txt");

	goertzel << "Hz697" << " " << "Hz770" << " ";
	goertzel << "Hz852" << " " << "Hz941" << " ";
	goertzel << "Hz1209" << " " << "Hz1336" << " ";
	goertzel << "Hz1477" << " " << "Hz1633" << std::endl;
	

	for (std::size_t i = 0; i < m_goertzelDataMatrix.size(); i++)
	{
		for (std::size_t j = 0; j < m_goertzelDataMatrix[i].size(); j++)
		{
			goertzel << m_goertzelDataMatrix[i][j] << " ";
		}
		goertzel << std::endl;
	}
	goertzel.close();
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

 			if (duration > sendingTime)
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

