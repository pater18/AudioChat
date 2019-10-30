#include "Decoder.h"
#include <bitset>
#include <algorithm>




Decoder::Decoder()
{
}

void Decoder::intToBit()
{

	std::cout << " Den er her " << std::endl; 
	for (size_t i = 0; i < sendToDecoder.size(); i++)
	{
		std::bitset<4> temp(sendToDecoder[i]);
		std::cout << temp << std::endl;
		vecForCRC.push_back(temp[3]);
		vecForCRC.push_back(temp[2]);
		vecForCRC.push_back(temp[1]);
		vecForCRC.push_back(temp[0]);
	}
	for (size_t i = 0; i < vecForCRC.size(); i++)
	{
		std::cout << vecForCRC[i];
	}
}


std::vector<int> Decoder::CRC(int antal_bit)
{

	std::bitset<64> generator2(0b00100000111);
	int DataInsert = antal_bit + 8 - 1;
	int indSize2 = vecForCRC.size();
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
		vecForCRC.insert(vecForCRC.begin(), 0);
	}

	int fejl = 0; 

	for (size_t k = 0; k < vecForCRC.size(); k += antal_bit + 8) //k=8    vecForCRC = 64
	{
		 
		std::bitset<64> data2(0b0);

		for (int i = 0; i < (antal_bit + 8); i++)
		{
			if (vecForCRC[i + k] == 1)
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
		

		std::vector<int> temp;
		for (size_t i = 0; i < antal_bit; i++)
		{
			temp.push_back(data2[i+8]);
		}
		std::reverse(std::begin(temp), std::end(temp));

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
		{
			std::cout << "Data der blev sendt var det rigtige" << std::endl;
			for (size_t i = 0; i < temp.size(); i++)
			{
				_CRCok.push_back(temp[i]);
			}
			fejl++;
		}
		else
		{
			std::cout << "Der er fejl i beregningen til CRC tjek." << std::endl;
			fejl++; 
			customSound fejl_besked;
			fejl_besked.StrToBit((char)fejl);
			fejl_besked.CRC(32);
			fejl_besked.message(5000);
		}
			
		 
	}

	return _CRCok;
}


void Decoder::bitToString()
{
	for (size_t u = 0; u < _CRCok.size(); u += 8)
	{
		std::bitset<8> temp;
		for (size_t i = 0; i < 8; i++)
		{
			if (_CRCok[i + u] == 1)
				temp.set(7 - i, 1);
			else
				temp.set(7 - i, 0);
		}

		int tempi = temp.to_ulong();
		char tempc = (char)tempi;
		besked.push_back(tempc);

	}
	
	std::cout << besked << std::endl;
	}

