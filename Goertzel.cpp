#include "Goertzel.h"

Goertzel::Goertzel()
{
}

Goertzel::Goertzel(int _N, int _sample_rate)
{
	N = _N;
	sample_rate = _sample_rate;
	k = (0.5 + (N * target_freq) / sample_rate);
	W = (2 * 3.14159265359 / N) * k;
	cosine = std::cos(W);
	sine = std::sin(W);
	coeff = 2 * cosine;

}

int Goertzel::goertzelResult(int _target_freq)
{
	target_freq = _target_freq;
	std::vector<int> vecSample = { 1, 2, 3, 4 };

	for (int i = 0; i = N - 1; i++)
	{
		Q0 = coeff * Q1 - Q2 + vecSample[i];
		Q2 = Q1;
		Q1 = Q0;

		magnitude += sqrt(pow(Q1, 2) + pow(Q2, 2) - Q1 * Q2 * coeff);
	}

	magnitude = magnitude / N;
	return magnitude;
}
