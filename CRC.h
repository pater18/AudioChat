#pragma once
#include <SFML/Audio.hpp>
#include "Sound.h"
#include "StringToBit.h"

#include <vector>


std::vector<sf::Int16> CRC(std::vector<int> streng, std::vector<sf::Int16>& ud) 
{
	for (size_t k = 0; k < streng.size(); k += 8)
	{

		std::bitset<16> generator(0b0000000100000111);  // CRC_8 check generator polynomie 

		std::bitset<16> data(0b0);						// Vektor til at lave udregninger på.

		for (int i = 0; i < 8; i++) 					// I dette loop indsættes data fra strengen ind i et bitset, så det senere kan manipuleres med. 
		{												// Det er 8 da vi laver tjek på hver 8 bit. Samtidig lægges de 8 bit i en ny vektor. 

			if (streng[i + k] == 1)
			{
				data.set(15 - i, 1);
				ud.push_back(1);
			}
			else
			{
				data.set(15 - i, 0);
				ud.push_back(0);
			}

		}

		std::cout << "Data: " << data << std::endl;

		for (int i = 0; i < 8; i++)
		{
			if (data[15 - i] == 1)
			{

				data[15 - i] = data[15 - i] xor generator[8];
				data[14 - i] = data[14 - i] xor generator[7];
				data[13 - i] = data[13 - i] xor generator[6];
				data[12 - i] = data[12 - i] xor generator[5];
				data[11 - i] = data[11 - i] xor generator[4];
				data[10 - i] = data[10 - i] xor generator[3];
				data[9 - i] = data[9 - i] xor generator[2];
				data[8 - i] = data[8 - i] xor generator[1];
				data[7 - i] = data[7 - i] xor generator[0];
			}
		}


		std::cout << "Rest efter division: ";
		for (int i = 0; i < 8; i++)
		{
			ud.push_back(data[7 - i]);
			std::cout << data[7 - i];
		}
		std::cout << std::endl;



		std::cout << "Binary streng der skal sendes: ";
		for (size_t i = 0; i < ud.size(); i++)
		{
			std::cout << ud[i];
		}
		std::cout << std::endl << std::endl;


	}

	//--------------------------------------------------------
	//CRC beregning tilbage til data for at tjekke at den giver nul

	/*std::bitset<16> generator2(0b00100000111);

	std::bitset<16> data2(0b0101011110100010);
	


	std::cout << "Data start: " << data2 << std::endl;

	for (int i = 0; i < 8; i++) 
	{
		if (data2[15 - i] == 1)
		{

			data2[15 - i] = data2[15 - i] xor generator2[8];
			data2[14 - i] = data2[14 - i] xor generator2[7];
			data2[13 - i] = data2[13 - i] xor generator2[6];
			data2[12 - i] = data2[12 - i] xor generator2[5];
			data2[11 - i] = data2[11 - i] xor generator2[4];
			data2[10 - i] = data2[10 - i] xor generator2[3];
			data2[9 - i] = data2[9 - i] xor generator2[2];
			data2[8 - i] = data2[8 - i] xor generator2[1];
			data2[7 - i] = data2[7 - i] xor generator2[0];
		}
	}

	std::cout << "Data: " << data2 << std::endl;*/

	return ud;
}