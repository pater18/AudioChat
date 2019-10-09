#pragma once
#include <cmath>
#include <vector>


class Goertzel
{
public:
	Goertzel();
	Goertzel(int _N, int _sample_rate);

	int goertzelResult(int _target_freq);



private:

	int target_freq;
	int sample_rate;
	int N;
	float k;
	float W;
	float cosine;
	float sine;
	float coeff;
	float Q0;
	float Q1 = 0;
	float Q2 = 0;
	float magnitude;
};
