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

void Encoder::setBit(int antalBit)
{
	m_antalBit = antalBit; 
}

void Encoder::slet() {
	m_CRCstreng.clear();
}

std::vector<sf::Int16> Encoder::StrToBit(sf::String input)
{
	std::vector<int> stringToBitVec;

	int StrLenght = input.getSize();

	for (int i = 0; i < input.getSize(); i++)
	{

		stringToBitVec.push_back(input[i]);					//Put hvert bogstav i en vektor 

		std::string binary = std::bitset<8>(stringToBitVec[i]).to_string(); //Converter hvert bogstav til en bitstreng.

		//std::cout << "Streng: " << binary << std::endl;					//Udskriver bitstrengen for det bogstav

		for (int i = 0; i < 8; i++)
		{
			int temp = (int)binary[i];
			if (temp == 48)
			{
				m_binStreng.push_back(0);
			}
			else
			{
				m_binStreng.push_back(1);
			}
		}
	}

	std::cout << "Besked skrevet i bit: ";
	for (size_t i = 0; i < m_binStreng.size(); i++)			//Tjek til at se der sker det rigtige 
	{
		std::cout << m_binStreng[i];
	}
	std::cout << std::endl; 

	return m_binStreng;
}

	

std::vector<sf::Int16> Encoder::CRC(std::vector<sf::Int16> bitStrengCRC)
{
	int indSize = bitStrengCRC.size();
	int paddingCoeff = 0;

	while (indSize > (paddingCoeff * m_antalBit))
		paddingCoeff++;

	m_numPadding = paddingCoeff * m_antalBit - indSize;

	std::cout << "Antal nuller der puttes i som padding: " << m_numPadding << std::endl;


	for (int i = 0; i < m_numPadding; i++)
	{
		bitStrengCRC.insert(bitStrengCRC.begin(), 0);
	}


	int DataInsert = m_antalBit + 8 - 1;					//32 + 8 - 1 = 39 

	for (size_t k = 0; k < bitStrengCRC.size(); k += m_antalBit) //k=8
	{

		std::bitset<64> generator(0b0000000100000111);  // CRC_8 check generator polynomie 

		std::bitset<64> data(0b0);						// Vektor til at lave udregninger på.

		for (int i = 0; i < m_antalBit; i++) //=8					// I dette loop indsættes data fra strengen ind i et bitset, så det senere kan manipuleres med. 
		{												// Det er 8 da vi laver tjek på hver 8 bit. Samtidig lægges de 8 bit i en ny vektor. 

			if (bitStrengCRC[i + k] == 1)
			{
				data.set(DataInsert - i, 1); //15
				m_CRCstreng.push_back(1);
			}
			else
			{
				data.set(DataInsert - i, 0); //15
				m_CRCstreng.push_back(0);
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
			m_CRCstreng.push_back(data[7 - i]);
			std::cout << data[7 - i];
		}
		std::cout << std::endl;
	}
	return m_CRCstreng;
}

std::vector<sf::Int16> Encoder::ESC(std::vector<sf::Int16> bitStrengESC)
{
	std::vector<int> ESCknap = { 1,1,1,1,1,1,1,0 };
	std::cout << "Binary streng der skal laves m_insertESC paa: ";
  
	for (size_t i = 0; i < bitStrengESC.size(); i++)
	{
		std::cout << bitStrengESC[i];
	}

	std::cout << std::endl << "Stoerrelse paa bitStrengESC: " << bitStrengESC.size() << std::endl;

	//Stop and wait m_insertESC for encoder
	for (size_t i = 0; i < bitStrengESC.size(); i += 8)
	{
		if ((bitStrengESC[i] == 1) && (bitStrengESC[i + 1] == 1) && (bitStrengESC[i + 2] == 1) && (bitStrengESC[i + 3] == 1) && (bitStrengESC[i + 4] == 0) && (bitStrengESC[i + 5] == 0) && (bitStrengESC[i + 6] == 0) && (bitStrengESC[i + 7] == 0))
		{
			//std::cout << "flag fundet";
			m_insertESC.push_back(1);
			m_insertESC.push_back(1);
			m_insertESC.push_back(1);
			m_insertESC.push_back(1);
			m_insertESC.push_back(1);
			m_insertESC.push_back(1);
			m_insertESC.push_back(1);
			m_insertESC.push_back(0);
			m_insertESC.push_back(bitStrengESC[i]);
			m_insertESC.push_back(bitStrengESC[i + 1]);
			m_insertESC.push_back(bitStrengESC[i + 2]);
			m_insertESC.push_back(bitStrengESC[i + 3]);
			m_insertESC.push_back(bitStrengESC[i + 4]);
			m_insertESC.push_back(bitStrengESC[i + 5]);
			m_insertESC.push_back(bitStrengESC[i + 6]);
			m_insertESC.push_back(bitStrengESC[i + 7]);
		}
		else if ((bitStrengESC[i] == 1) && (bitStrengESC[i + 1] == 1) && (bitStrengESC[i + 2] == 1) && (bitStrengESC[i + 3] == 1) && (bitStrengESC[i + 4] == 1) && (bitStrengESC[i + 5] == 1) && (bitStrengESC[i + 6] == 1) && (bitStrengESC[i + 7] == 0))
		{
			//std::cout << "ESC char fundet";
			m_insertESC.push_back(1);
			m_insertESC.push_back(1);
			m_insertESC.push_back(1);
			m_insertESC.push_back(1);
			m_insertESC.push_back(1);
			m_insertESC.push_back(1);
			m_insertESC.push_back(1);
			m_insertESC.push_back(0);
			m_insertESC.push_back(bitStrengESC[i]);
			m_insertESC.push_back(bitStrengESC[i + 1]);
			m_insertESC.push_back(bitStrengESC[i + 2]);
			m_insertESC.push_back(bitStrengESC[i + 3]);
			m_insertESC.push_back(bitStrengESC[i + 4]);
			m_insertESC.push_back(bitStrengESC[i + 5]);
			m_insertESC.push_back(bitStrengESC[i + 6]);
			m_insertESC.push_back(bitStrengESC[i + 7]);
		}
		else
		{
			m_insertESC.push_back(bitStrengESC[i]);
			m_insertESC.push_back(bitStrengESC[i + 1]);
			m_insertESC.push_back(bitStrengESC[i + 2]);
			m_insertESC.push_back(bitStrengESC[i + 3]);
			m_insertESC.push_back(bitStrengESC[i + 4]);
			m_insertESC.push_back(bitStrengESC[i + 5]);
			m_insertESC.push_back(bitStrengESC[i + 6]);
			m_insertESC.push_back(bitStrengESC[i + 7]);
		}

	}

	for (size_t i = 0; i < m_insertESC.size(); i++)
	{
		std::cout << m_insertESC[i];
	}
	std::cout << std::endl;


	return m_insertESC;

}

std::vector<std::vector<sf::Int16>> Encoder::pakker(std::vector<sf::Int16> bitStrengPakker)
{

	int j = 0, protoStart = 0, protoSlut = m_antalBit + 8, length = 0;
	length = bitStrengPakker.size();

	if (length % (m_antalBit + 8) == 0)
	{
		m_pakker.resize(length / (m_antalBit + 8));
	}
	else
	{
		m_pakker.resize((length / (m_antalBit + 8)) + 1);
	}

	for (size_t i = 0; i < m_pakker.size(); i++)
	{
		if (i % 2 == 0)
		{
			if (protoStart + (m_antalBit + 8) < bitStrengPakker.size())
			{
				m_pakker[i].insert(m_pakker[i].end(), bitStrengPakker.begin() + protoStart, bitStrengPakker.begin() + protoSlut);
			}
			else
			{
				m_pakker[i].insert(m_pakker[i].end(), bitStrengPakker.begin() + protoStart, bitStrengPakker.end());
			}

			protoStart += (m_antalBit + 8);
			protoSlut += (m_antalBit + 8);
		}
		else
		{

			if (protoStart + (m_antalBit + 8) < bitStrengPakker.size())
			{
				m_pakker[i].insert(m_pakker[i].end(), bitStrengPakker.begin() + protoStart, bitStrengPakker.begin() + protoSlut);
			}
			else
			{
				m_pakker[i].insert(m_pakker[i].end(), bitStrengPakker.begin() + protoStart, bitStrengPakker.end());
			}

			protoStart += (m_antalBit + 8);
			protoSlut += (m_antalBit + 8);

		}

		if (i == 0 && m_numPadding > 0)
		{
			std::cout << "m_numPadding: " << m_numPadding << std::endl; 
			m_pakker[0].erase(m_pakker[0].begin(), m_pakker[0].begin() + m_numPadding);
		}
	}
	for (size_t i = 0; i < m_pakker.size(); i++)
	{
		for (size_t j = 0; j < m_pakker[i].size(); j++)
		{
			std::cout << m_pakker[i][j];
		}
		std::cout << " ";

	}
	return m_pakker;
}

std::vector<std::vector<sf::Int16> > Encoder::header(std::vector<std::vector<sf::Int16> > headerVec)
{
	int flag[8] = { 1,1,1,1,0,0,0,0 };
	int sek0[8] = { 0,0,0,0,0,0,0,0 };
	int sek1[8] = { 0,0,0,0,0,0,0,1 };

	for (size_t i = 0; i < headerVec.size(); i++)
	{
		if (i % 2 == 0)
		{
			headerVec[i].insert(headerVec[i].begin(), flag, flag + 8);
			headerVec[i].insert(headerVec[i].begin() + 8, sek0, sek0 + 8);
			headerVec[i].insert(headerVec[i].end(), flag, flag + 8);
		}
		else
		{
			headerVec[i].insert(headerVec[i].begin(), flag, flag + 8);
			headerVec[i].insert(headerVec[i].begin() + 8, sek1, sek1 + 8);
			headerVec[i].insert(headerVec[i].end(), flag, flag + 8);
		}
	}
	for (size_t i = 0; i < headerVec.size(); i++)
	{
		for (size_t j = 0; j < headerVec[i].size(); j++)
		{
			std::cout << headerVec[i][j];
		}
		std::cout << " ";
		m_pakkerMedHeader = headerVec;
	}
	return m_pakkerMedHeader;
}

std::vector<std::vector<sf::Int16>> Encoder::encoderMessage(std::string message)
{
	setBit(32);
	auto bitstring = StrToBit(message);
	for (size_t i = 0; i < bitstring.size(); i++)
	{
		std::cout << bitstring[i];
	}
	std::cout << std::endl;

	auto CRCbitString = CRC(bitstring);
	for (size_t i = 0; i < CRCbitString.size(); i++)
	{
		std::cout << CRCbitString[i] << "A";
	
	}
	std::cout << std::endl;

	auto EscBitString = ESC(CRCbitString);
	std::cout << "3" << std::endl;
	auto pakkeBitString = pakker(EscBitString);
	std::cout << "4" << std::endl;
	auto headerBitString = header(pakkeBitString);
	std::cout << "5" << std::endl;

	return headerBitString;
}


