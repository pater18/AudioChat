#pragma once
#include "Encoder.h"

#include <math.h>
#include <vector>
#include <string>
#include <string>
#include <bitset>
#include <iostream>
#include <fstream>


class customSound: public Encoder
{

public: 
//#define TWOPI 6.283185307;
	customSound();
	short Sinewave(double time, double freq1, double freq2, double amp);
	std::vector<sf::Int16> message(int tid);
	std::vector<sf::Int16> _customSound;
private:
	
	short _result; 
};


	

