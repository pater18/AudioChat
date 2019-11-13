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

	for (size_t i = 0; i < _Encoded.size(); i++)			//Tjek til at se der sker det rigtige 
	{
		std::cout << _Encoded[i];
	}
	std::cout << std::endl; 

	return _Encoded;
}


std::vector<sf::Int16> Encoder::CRC(int antal_bit)
{
	// Skal have lavet padding så det er ligegyldigt hvor mange karakter men vælger at skrive. 

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

	std::cout << std::endl << "Størrelse på ud: " << ud.size() << std::endl;


	

	return ud;
}

//void Encoder::tjekDouble()
//{
//	bool temp1 = false;
//	bool temp2 = false;
//	bool temp3 = false;
//	bool temp4 = false;
//
//	int count = 0; 
//	int countAdd = 0;
//	std::vector<int> tempD; 
//
//	std::cout << "Størrelse til start: " << ud.size() << std::endl; 
//
//	for (size_t i = 0; i < ud.size() - 4; i += 4)
//	{
//		temp1 = false;
//		
//		if ((ud[i] == ud[i + 4]) && ud[i + 1] == ud[i + 5] && ud[i + 2] == ud[i + 6] && ud[i + 3] == ud[i + 7])
//			temp1 = true;
//
//		if (temp1  == true)
//			count++;
//	}
//	std::cout << "count before: " << count << std::endl;
//	count = 0; 
//
//	tempD.push_back(ud[0]);
//	tempD.push_back(ud[1 + 1]);
//	tempD.push_back(ud[2 + 2]);
//	tempD.push_back(ud[3 + 3]);
//
//	for (size_t i = 0; i < ud.size() - 4; i+= 4)
//	{
//		
//		if ((ud[i] == ud[i + 4]) && ud[i + 1] == ud[i + 5] && ud[i + 2] == ud[i + 6] && ud[i + 3] == ud[i + 7])
//		{
//
//			if (ud[i] && ud[i + 1] && ud[i + 2] && ud[i + 3] == 1)
//			{
//				tempD.push_back(0);
//				tempD.push_back(0);
//				tempD.push_back(0);
//				tempD.push_back(0);
//
//				tempD.push_back(ud[i + 4]);
//				tempD.push_back(ud[i + 5]);
//				tempD.push_back(ud[i + 6]);
//				tempD.push_back(ud[i + 7]);
//				countAdd++; 
//				std::cout << "der er 8 1-tal" << std::endl;
//			}
//			else
//			{
//				tempD.push_back(1);
//				tempD.push_back(1);
//				tempD.push_back(1);
//				tempD.push_back(1);
//
//				tempD.push_back(ud[i + 4]);
//				tempD.push_back(ud[i + 5]);
//				tempD.push_back(ud[i + 6]);
//				tempD.push_back(ud[i + 7]);
//			}
//
//			countAdd++;
//
//			std::cout << "der bliver tilføret 1111" << std::endl; 
//		}
//		else
//		{
//			tempD.push_back(ud[i + 4]);
//			tempD.push_back(ud[i + 5]);
//			tempD.push_back(ud[i + 6]);
//			tempD.push_back(ud[i + 7]);
//		}
//
//
//
//	}
//
//
//	for (size_t i = 0; i < tempD.size() - 4; i += 4)
//	{
//		temp1 = false;
//
//		if ((tempD[i] == tempD[i + 4]) && tempD[i + 1] == tempD[i + 5] && tempD[i + 2] == tempD[i + 6] && tempD[i + 3] == tempD[i + 7])
//			temp1 = true;
//
//		if (temp1 == true)
//			count++;
//	}	
//
//	
//	std::cout << countAdd << std::endl;
//	std::cout << count << std::endl; 
//	//-------------------------------------------------------
//
//	std::vector<int> rigtige;
//
//
//	rigtige.push_back(tempD[0]);
//	rigtige.push_back(tempD[1]);
//	rigtige.push_back(tempD[2]);
//	rigtige.push_back(tempD[3]);
//
//
//	for (size_t i = 0; i < tempD.size() - 8; i += 4)
//	{
//		temp1 = false;
//
//		if ((tempD[i] == tempD[i + 8]) && tempD[i + 1] == tempD[i + 9] && tempD[i + 2] == tempD[i + 10] && tempD[i + 3] == tempD[i + 11])
//		{
//			if (tempD[i + 4] && tempD[i + 5] && tempD[i + 6] && tempD[i + 7] == 1)
//			{
//				rigtige.push_back(tempD[8]);
//				rigtige.push_back(tempD[9]);
//				rigtige.push_back(tempD[10]);
//				rigtige.push_back(tempD[11]);
//			}
//			if (tempD[i] && tempD[i + 2] && tempD[i + 3] && tempD[i + 4] == 1)
//			{
//				rigtige.push_back(tempD[8]);
//				rigtige.push_back(tempD[9]);
//				rigtige.push_back(tempD[10]);
//				rigtige.push_back(tempD[11]);
//			}
//		}
//		else
//		{
//			rigtige.push_back(tempD[5]);
//			rigtige.push_back(tempD[6]);
//			rigtige.push_back(tempD[7]);
//			rigtige.push_back(tempD[8]);
//		}
//
//	}
//	std::cout << "Størrelse af rigtige: " << rigtige.size() << std::endl;
//
//}

