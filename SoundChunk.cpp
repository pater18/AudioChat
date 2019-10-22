#include "SoundChunk.h"

#define PI 3.14159265359

std::vector<float> SoundChunk::goertzelAlgorithm(int samplingFreq)
{
	std::vector<float> result;
	for (std::size_t i = 0; i < m_DtmfFreq.size(); i++)
	{
		int k = 0.5 + ((m_sampleCount * m_DtmfFreq[i]) / samplingFreq);
		float w = ((2 * PI) / m_sampleCount) * k;
		float cosw = std::cos(w);
		float sinw = std::sin(w);
		float coeff = 2 * cosw;

		float Q0 = 0, Q1 = 0, Q2 = 0;

		for (std::size_t i = 0; i < m_sampleCount; i++)
		{
			Q0 = coeff * Q1 - Q2 + m_samples[i];
			Q2 = Q1;
			Q1 = Q0;
		}

		float magnitude = std::sqrt(std::pow(Q1, 2) + std::pow(Q2, 2) - (Q1 * Q2 * coeff));

		result.push_back(magnitude);

	}
	return result;
}
