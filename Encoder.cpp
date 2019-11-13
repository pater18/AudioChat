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

	

std::vector<sf::Int16> Encoder::CRC()
{
	int indSize = _Encoded.size();
	int paddingCoeff = 0;

	while (indSize > (paddingCoeff * m_antalBit))
		paddingCoeff++;

	int numPadding = paddingCoeff * m_antalBit - indSize;

	std::cout << "Antal nuller der puttes i som padding: " << numPadding << std::endl;


	for (int i = 0; i < numPadding; i++)
	{
		_Encoded.insert(_Encoded.begin(), 0);
	}


	int DataInsert = m_antalBit + 8 - 1;					//32 + 8 - 1 = 39 

	for (size_t k = 0; k < _Encoded.size(); k += m_antalBit) //k=8
	{

		std::bitset<64> generator(0b0000000100000111);  // CRC_8 check generator polynomie 

		std::bitset<64> data(0b0);						// Vektor til at lave udregninger på.

		for (int i = 0; i < m_antalBit; i++) //=8					// I dette loop indsættes data fra strengen ind i et bitset, så det senere kan manipuleres med. 
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

	std::cout << "Binary streng der skal laves insertESC p�: ";
  
	for (size_t i = 0; i < ud.size(); i++)
	{
		std::cout << ud[i];
	}

	std::cout << std::endl << "St�rrelse p� ud: " << ud.size() << std::endl;

	//Stop and wait insertESC for encoder
	for (size_t i = 0; i < ud.size(); i += 8)
	{
		if ((ud[i] == 1) && (ud[i + 1] == 1) && (ud[i + 2] == 1) && (ud[i + 3] == 1) && (ud[i + 4] == 0) && (ud[i + 5] == 0) && (ud[i + 6] == 0) && (ud[i + 7] == 0))
		{
			//std::cout << "flag fundet";
			insertESC.push_back(1);
			insertESC.push_back(1);
			insertESC.push_back(1);
			insertESC.push_back(1);
			insertESC.push_back(1);
			insertESC.push_back(1);
			insertESC.push_back(1);
			insertESC.push_back(0);
			insertESC.push_back(ud[i]);
			insertESC.push_back(ud[i + 1]);
			insertESC.push_back(ud[i + 2]);
			insertESC.push_back(ud[i + 3]);
			insertESC.push_back(ud[i + 4]);
			insertESC.push_back(ud[i + 5]);
			insertESC.push_back(ud[i + 6]);
			insertESC.push_back(ud[i + 7]);
		}
		else if ((ud[i] == 1) && (ud[i + 1] == 1) && (ud[i + 2] == 1) && (ud[i + 3] == 1) && (ud[i + 4] == 1) && (ud[i + 5] == 1) && (ud[i + 6] == 1) && (ud[i + 7] == 0))
		{
			//std::cout << "ESC char fundet";
			insertESC.push_back(1);
			insertESC.push_back(1);
			insertESC.push_back(1);
			insertESC.push_back(1);
			insertESC.push_back(1);
			insertESC.push_back(1);
			insertESC.push_back(1);
			insertESC.push_back(0);
			insertESC.push_back(ud[i]);
			insertESC.push_back(ud[i + 1]);
			insertESC.push_back(ud[i + 2]);
			insertESC.push_back(ud[i + 3]);
			insertESC.push_back(ud[i + 4]);
			insertESC.push_back(ud[i + 5]);
			insertESC.push_back(ud[i + 6]);
			insertESC.push_back(ud[i + 7]);
		}
		else
		{
			insertESC.push_back(ud[i]);
			insertESC.push_back(ud[i + 1]);
			insertESC.push_back(ud[i + 2]);
			insertESC.push_back(ud[i + 3]);
			insertESC.push_back(ud[i + 4]);
			insertESC.push_back(ud[i + 5]);
			insertESC.push_back(ud[i + 6]);
			insertESC.push_back(ud[i + 7]);
		}

	}

	for (size_t i = 0; i < insertESC.size(); i++)
	{
		std::cout << insertESC[i];
	}
	std::cout << std::endl;


	return insertESC;

}

std::vector<std::vector<sf::Int16>> Encoder::sendBuffer(std::vector<sf::Int16> _CRC)
{
	int j = 0, protoStart = 0, protoSlut = 40, length = 0;
	int flag[8] = { 1,1,1,1,0,0,0,0 };
	int sek0[8] = { 0,0,0,0,0,0,0,0 };
	int sek1[8] = { 0,0,0,0,0,0,0,1 };
	length = insertESC.size();

	if (length % 40 == 0)
	{
		vecSendBuffer.resize(length / 40);
	}
	else
	{
		vecSendBuffer.resize((length / 40) + 1);
	}

	for (size_t i = 0; i < vecSendBuffer.size(); i++)
	{
		if (i % 2 == 0)
		{
			vecSendBuffer[i].insert(vecSendBuffer[i].begin(), flag, flag+8);
			vecSendBuffer[i].insert(vecSendBuffer[i].end(), sek0, sek0 + 8);
			if (protoStart + 40 < insertESC.size())
			{
				vecSendBuffer[i].insert(vecSendBuffer[i].end(), insertESC.begin() + protoStart, insertESC.begin() + protoSlut);
			}
			else
			{
				vecSendBuffer[i].insert(vecSendBuffer[i].end(), insertESC.begin() + protoStart, insertESC.end());
			}
			vecSendBuffer[i].insert(vecSendBuffer[i].end(), flag, flag + 8);
			protoStart += 40;
			protoSlut += 40;
		}
		else
		{
			vecSendBuffer[i].insert(vecSendBuffer[i].begin(), flag, flag + 8);
			vecSendBuffer[i].insert(vecSendBuffer[i].end(), sek1, sek1 + 8);
			if (protoStart + 40 < insertESC.size())
			{
				vecSendBuffer[i].insert(vecSendBuffer[i].end(), insertESC.begin() + protoStart, insertESC.begin() + protoSlut);
			}
			else
			{
				vecSendBuffer[i].insert(vecSendBuffer[i].end(), insertESC.begin() + protoStart, insertESC.end());
			}
			vecSendBuffer[i].insert(vecSendBuffer[i].end(), flag, flag + 8);
			protoStart += 40;
			protoSlut += 40;

		}
	}
	for (size_t i = 0; i < vecSendBuffer.size(); i++)
	{
		for (size_t j = 0; j < vecSendBuffer[i].size(); j++)
		{
			std::cout << vecSendBuffer[i][j];
		}
		std::cout << " ";

	}
	return vecSendBuffer;
}


