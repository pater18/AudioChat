#pragma once
#include <math.h>
#include <vector>
#include <string>
#include <string>
#include <bitset>
#include <iostream>




namespace sound {

#define TWOPI 6.283185307

	short SineWave(double time, double freq1, double freq2, double amp) {
		short result1;
		double tpc1 = 44100 / freq1;
		double cycles1 = time / tpc1;
		double rad1 = TWOPI * cycles1;
		short amplitude = 32767 * amp;
		result1 = amplitude * sin(rad1);

		short result2;
		double tpc2 = 44100 / freq2;
		double cycles2 = time / tpc2;
		double rad2 = TWOPI * cycles2;
		result2 = amplitude * sin(rad2);



		return result1 + result2;

	}
	
}

	

