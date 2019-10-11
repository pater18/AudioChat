#include "StringToBit.h"


std::vector<int>  StrToBit(std::vector<int>& binaryString, std::string input)
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
			binaryString.push_back(0);
		}
		else
		{
			binaryString.push_back(1);
		}
	}
}

std::cout << "Strengen skrevet i bit: ";

for (size_t i = 0; i < binaryString.size(); i++)			//Tjek til at se der sker det rigtige 
{
	std::cout << binaryString[i];
}

std::cout << std::endl; 

return binaryString;
}