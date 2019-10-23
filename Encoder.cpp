#include "Encoder.h"

#include <math.h>
#include <vector>
#include <string>
#include <string>
#include <bitset>
#include <iostream>

Encoder::Encoder()
{
}

std::vector<sf::Int16> Encoder::StrToBit(std::string input)
{

	std::vector<int> binString;
	int StrLenght = input.length();

	for (int i = 0; i < input.length(); i++)
	{
		binString.push_back(input[i]);					//Put hvert bogstav i en vektor 

		std::string binary = std::bitset<8>(binString[i]).to_string(); //Converter hvert bogstav til en bitstreng.

		//std::cout << "Streng: " << binary << std::endl;					//Udskriver bitstrengen for det bogstav

		for (int i = 0; i < 8; i++)
		{
			int temp = (int)binary[i];
			if (temp == 48)
			{
				_Encoded.push_back(0);
			}
			else
			{
				_Encoded.push_back(1);
			}

		}

	}

	std::cout << "Strengen skrevet i bit: ";

	std::cout << std::endl;

	for (size_t i = 0; i < _Encoded.size(); i++)			//Tjek til at se der sker det rigtige 
	{
		std::cout << _Encoded[i];
	}

	return _Encoded;
}


std::vector<sf::Int16> Encoder::CRC(int antal_bit)
{ 

	int indSize = _Encoded.size();
	int paddingCoeff = 0;

	while (indSize > (paddingCoeff * antal_bit))
		paddingCoeff++;

	int numPadding = paddingCoeff * antal_bit - indSize;

	std::cout << "Antal nuller der puttes i som padding: " << numPadding << std::endl;


	for (int i = 0; i < numPadding; i++)
	{
		_Encoded.insert(_Encoded.begin(), 0);
	}



	int DataInsert = antal_bit + 8 - 1;					//32 + 8 - 1 = 39 

	for (size_t k = 0; k < _Encoded.size(); k += antal_bit) //k=8
	{

		std::bitset<64> generator(0b0000000100000111);  // CRC_8 check generator polynomie 

		std::bitset<64> data(0b0);						// Vektor til at lave udregninger på.

		for (int i = 0; i < antal_bit; i++) //=8					// I dette loop indsættes data fra strengen ind i et bitset, så det senere kan manipuleres med. 
		{												// Det er 8 da vi laver tjek på hver 8 bit. Samtidig lægges de 8 bit i en ny vektor. 

			if (_Encoded[i + k] == 1)
			{
				data.set(DataInsert - i, 1); //15
				ud.push_back(1);
			}
			else
			{
				data.set(DataInsert - i, 0); //15
				ud.push_back(0);
			}

		}

		std::cout << "Data: " << data << std::endl;

		for (int i = 0; i < antal_bit; i++) //8
		{
			if (data[DataInsert - i] == 1)
			{
				data[DataInsert - i] = data[DataInsert - i] xor generator[8];
				data[DataInsert - 1 - i] = data[DataInsert - 1 - i] xor generator[7];
				data[DataInsert - 2 - i] = data[DataInsert - 2 - i] xor generator[6];
				data[DataInsert - 3 - i] = data[DataInsert - 3 - i] xor generator[5];
				data[DataInsert - 4 - i] = data[DataInsert - 4 - i] xor generator[4];
				data[DataInsert - 5 - i] = data[DataInsert - 5 - i] xor generator[3];
				data[DataInsert - 6 - i] = data[DataInsert - 6 - i] xor generator[2];
				data[DataInsert - 7 - i] = data[DataInsert - 7 - i] xor generator[1];
				data[DataInsert - 8 - i] = data[DataInsert - 8 - i] xor generator[0];
			}
		}



		std::cout << "Rest efter division: ";
		for (int i = 0; i < 8; i++)
		{
			ud.push_back(data[7 - i]);
			std::cout << data[7 - i];
		}
		std::cout << std::endl;





	}

	ud.erase(ud.begin(), ud.begin() + numPadding);
	std::cout << "Binary streng der skal sendes: ";
	for (size_t i = 0; i < ud.size(); i++)
	{
		std::cout << ud[i];
	}

	std::cout << std::endl << std::endl;


	//--------------------------------------------------------
	//CRC beregning tilbage til data for at tjekke at den giver nul

	std::bitset<64> generator2(0b00100000111);

	int indSize2 = ud.size();
	std::cout << indSize2 << std::endl;

	int paddingCoeff2 = 0;
	int tjek = indSize2 % (antal_bit + 8);


	while (tjek != 0)
	{
		indSize2 += 8;
		tjek = indSize2 % (antal_bit + 8);
		paddingCoeff2++;
	}

	int numPadding2 = paddingCoeff2 * 8;

	std::cout << "Antal nuller der puttes i som padding2: " << numPadding2 << std::endl;


	for (int i = 0; i < numPadding2; i++)
	{
		ud.insert(ud.begin(), 0);
	}

	for (size_t k = 0; k < ud.size(); k += antal_bit + 8) //k=8    ud = 64
	{
		std::bitset<64> data2(0b0);

		for (int i = 0; i < (antal_bit + 8); i++)
		{
			if (ud[i + k] == 1)
			{
				data2.set((antal_bit + 8) - 1 - i, 1);
			}
			else
			{
				data2.set((antal_bit + 8) - 1 - i, 0);
			}
		}

		std::cout << "Data2 start: ";
		std::cout << data2;
		std::cout << std::endl;

		for (int i = 0; i < antal_bit; i++)
		{
			if (data2[DataInsert - i] == 1)
			{
				data2[DataInsert - i] = data2[DataInsert - i] xor generator2[8];
				data2[DataInsert - 1 - i] = data2[DataInsert - 1 - i] xor generator2[7];
				data2[DataInsert - 2 - i] = data2[DataInsert - 2 - i] xor generator2[6];
				data2[DataInsert - 3 - i] = data2[DataInsert - 3 - i] xor generator2[5];
				data2[DataInsert - 4 - i] = data2[DataInsert - 4 - i] xor generator2[4];
				data2[DataInsert - 5 - i] = data2[DataInsert - 5 - i] xor generator2[3];
				data2[DataInsert - 6 - i] = data2[DataInsert - 6 - i] xor generator2[2];
				data2[DataInsert - 7 - i] = data2[DataInsert - 7 - i] xor generator2[1];
				data2[DataInsert - 8 - i] = data2[DataInsert - 8 - i] xor generator2[0];
			}
		}


		if (data2 == false)
			std::cout << "Data der blev sendt var det rigtige" << std::endl;
		else
			std::cout << "Der er fejl i beregningen til CRC tjek." << std::endl;

	}

	return ud;
}

//short Encoder::SineWave(double time, double freq1, double freq2, double amp)
//{
//	
//	double TWOPI = 6.283185307; 
//	short result1;
//	double tpc1 = 44100 / freq1;
//	double cycles1 = time / tpc1;
//	double rad1 = TWOPI * cycles1;
//	short amplitude = 32767 * amp;
//	result1 = amplitude * sin(rad1);
//
//	short result2;
//	double tpc2 = 44100 / freq2;
//	double cycles2 = time / tpc2;
//	double rad2 = TWOPI * cycles2;
//	result2 = amplitude * sin(rad2);
//
//
//
//	return result1 + result2;
//}