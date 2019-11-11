#include "Encoder.h"

#include <math.h>
#include <vector>
#include <string>
#include <string>
#include <bitset>
#include <iostream>


int numPadding;

Encoder::Encoder()
{
}

void Encoder::setBit(int antalBit)
{
	m_antalBit = antalBit; 
}

void Encoder::slet() {
	ud.clear();
	opdeltBesked.clear();
}

std::vector<sf::Int16> Encoder::StrToBit(sf::String input)
{

	std::vector<int> binString;
	int StrLenght = input.getSize();

	for (int i = 0; i < input.getSize(); i++)
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

	std::cout << "Besked skrevet i bit: ";
	for (size_t i = 0; i < _Encoded.size(); i++)			//Tjek til at se der sker det rigtige 
	{
		std::cout << _Encoded[i];
	}
	std::cout << std::endl; 

	return _Encoded;
}




void Encoder::opdel()
{
	
	int indSize = _Encoded.size();
	int paddingCoeff = 0;
	numPadding = 0;

	if (_Encoded.size() < m_antalBit)
	{
		while (indSize > (paddingCoeff * m_antalBit))
			paddingCoeff++;

		numPadding = paddingCoeff * m_antalBit - indSize;

		for (int i = 0; i < numPadding; i++)
		{
			opdeltBesked.insert(opdeltBesked.begin(), 0);
		}
	}

	for (int i = 0; i < m_antalBit - numPadding; i++)
		opdeltBesked.push_back(_Encoded[i]);


	std::cout << "Den enkelte pakke der sendes uden CRC - tjek: ";

	for (size_t i = 0; i < opdeltBesked.size(); i++)
	{
		std::cout << opdeltBesked[i];
	}

	std::cout << std::endl;
}

void Encoder::sletFrame()
{
	if (_Encoded.size() >= m_antalBit)
	{
		_Encoded.erase(_Encoded.begin(), _Encoded.begin() + m_antalBit);
	}
	else
		_Encoded.clear();

}
	

std::vector<sf::Int16> Encoder::CRC()
{

	int DataInsert = m_antalBit + 8 - 1;					//32 + 8 - 1 = 39 

	for (size_t k = 0; k < opdeltBesked.size(); k += m_antalBit) //k=8
	{

		std::bitset<64> generator(0b0000000100000111);  // CRC_8 check generator polynomie 

		std::bitset<64> data(0b0);						// Vektor til at lave udregninger på.

		for (int i = 0; i < m_antalBit; i++) //=8					// I dette loop indsættes data fra strengen ind i et bitset, så det senere kan manipuleres med. 
		{												// Det er 8 da vi laver tjek på hver 8 bit. Samtidig lægges de 8 bit i en ny vektor. 

			if (opdeltBesked[i + k] == 1)
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

		std::cout << "Det data bliver lavet CRC - tjek på: " << data << std::endl;

		for (int i = 0; i < m_antalBit; i++) //8
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


	return ud;
}
int Encoder::getSize()
{

	return StrLenght;
	  
}


