#include "SoundChunk.h"

#define PI 3.14159265359

void SoundChunk::hanningWindow()
{
	for (std::size_t i = 0; i < m_sampleCount; i++)
		m_samples[i] = m_samples[i] * ( 0.5 * (1 - std::cos((2 * PI * i) / (m_sampleCount - 1)))) + 0.5;
}

std::vector<float> SoundChunk::goertzelAlgorithm(int samplingFreq)
{
	std::vector<float> result;
	for (std::size_t j = 0; j < m_dtmfFreq.size(); j++)
	{
		float floatk = (((m_sampleCount * m_dtmfFreq[j])) / samplingFreq) + 0.5;
		int k = (int)floatk; 
		float w = ((2 * PI) / m_sampleCount) * k;
		float cosw = std::cos(w);
		float coeff = 2 * cosw;

		float Q0 = 0, Q1 = 0, Q2 = 0;

		for (std::size_t i = 0; i < m_sampleCount; i++)
		{
			Q0 = coeff * Q1 - Q2 + m_samples[i];
			Q2 = Q1;
			Q1 = Q0;
		}


		float magnitude = std::sqrt(std::pow(Q1, 2) + std::pow(Q2, 2) - Q1 * Q2 * coeff);
		//std::cout << magnitude << " ";
		result.push_back(magnitude);

	}
	return result;

}

int SoundChunk::determineDtmfTwo(std::vector<float> freqComponents)
{
	std::vector<float> lowerTones(freqComponents.begin(), freqComponents.begin() + 4);
	std::vector<float> higherTones(freqComponents.begin() + 4, freqComponents.end());
	

	float maxLower = *max_element(lowerTones.begin(), lowerTones.end());
	float maxHigher = *max_element(higherTones.begin(), higherTones.end());

	if (maxLower < threshHold || maxHigher < threshHold)
		return -1;

	int posLower = -1;
	for (std::size_t i = 0; i < lowerTones.size(); i++)
	{
		if (maxLower == lowerTones[i])
		{
			posLower = i;
			continue;
		}
		if (maxLower < lowerTones[i] * threshHoldMultiple)
			return -1;
	}

	int posHigher = -1;
	for (std::size_t i = 0; i < higherTones.size(); i++)
	{
		if (maxHigher == higherTones[i])
		{
			posHigher = i;
			continue;
		}
		if (maxHigher < higherTones[i] * threshHoldMultiple)
			return -1;
	}

	//std::cout << posLower << " " << posHigher << std::endl;
	//std::cout << higherTones.size() << std::endl;

	return m_dtmfLookup[posLower][posHigher];
}


int SoundChunk::determineDTMF(std::vector<float> freqComponents)
{
	std::vector<std::pair <int, float> > vect;
	for (std::size_t i = 0; i < freqComponents.size(); i++)
	{
		vect.push_back(std::make_pair(i, freqComponents[i]));
	}
	
	float largest = 0;
	int pos1 = 0;
	for (std::size_t i = 0; i < vect.size(); i++)
	{
		if (vect[i].second > largest)
		{
			largest = vect[i].second;
			pos1 = i;
		}
	}

	float secondLargest = 0;
	int pos2 = 0;
	for (std::size_t i = 0; i < vect.size(); i++)
	{
		if (vect[i].second > secondLargest)
		{
			if (vect[i].second == largest)
				continue;
			secondLargest = vect[i].second;
			pos2 = i;
		}
	}

	if (secondLargest < threshHold)
		return -1;

	for (std::size_t i = 0; i < vect.size(); i++)
	{	
		if (vect[i].second == secondLargest || vect[i].second == largest)
			continue;
		if (secondLargest / vect[i].second < threshHoldMultiple)
			return -1;
	}

	int temp;
	if (pos1 > 3)
	{
		temp = pos2;
		pos2 = pos1 - 4;
		pos1 = temp;
		if (pos1 > 3)
			pos1 = pos1 - 4;
	}
	if (pos2 > 3)
		pos2 = pos2 - 4;

	//sendToDecoder.push_back(m_dtmfLookup[pos1][pos2]);

	return m_dtmfLookup[pos1][pos2];
	//std::sort(vect.begin(), vect.end(), sortinrev);

	//for (std::size_t i = 0; i < vect.size(); i++)
	//{
	//	std::cout << vect[i].first << " " << vect[i].second << std::endl;
	//}
	
}

std::vector<float> SoundChunk::goertzelForTest(std::vector<short> samples, int samplingFreq)
{
	std::vector<float> result;
	for (std::size_t j = 0; j < m_dtmfFreq.size(); j++)
	{
		int k = (0.5 + ((samples.size() * m_dtmfFreq[j])) / samplingFreq);
		float w = ((2 * PI) / samples.size()) * k;
		float cosw = std::cos(w);
		float sinw = sin(w);
		float coeff = 2 * cosw;

		float Q0 = 0, Q1 = 0, Q2 = 0;

		if (samples.size() < 205)
		{
			std::cout << "FOR FÅ SAMPLES!";
			return result;
		}
		for (std::size_t i = 0; i < 205; i++)
		{
			Q0 = coeff * Q1 - Q2 + samples[i];
			Q2 = Q1;
			Q1 = Q0;
		}

		float magnitude = std::sqrt(std::pow(Q1, 2) + std::pow(Q2, 2) - Q1 * Q2 * coeff);
		//std::cout << magnitude << " ";
		result.push_back(magnitude);

	}
	//std::cout << std::endl;
	return result;
}
	


