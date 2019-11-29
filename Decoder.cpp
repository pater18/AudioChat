#include "Decoder.h"
#include <bitset>
#include <algorithm>




Decoder::Decoder()
{
}

void Decoder::setDTMFTone(int DTMF)
{
	double durationSinceLastDTMF;
	durationSinceLastDTMF = (std::clock() - messageTimeOut) / (double)CLOCKS_PER_SEC;
	if (durationSinceLastDTMF > m_timeOutDuration)
	{
		m_charVect.clear();
		m_character.clear();
		std::cout << "CLEAR" << std::endl;
		m_listening = true; 
	}
	messageTimeOut = std::clock();

	//m_vecAck.push_back(DTMF);
	if (m_character.size() == 2)
		m_character.clear();
	m_character.push_back(DTMF);
 
	std::cout << DTMF << " ";
	if (m_character.size() == 2)
		std::cout << std::endl;

	////Print hver karakter
	//if (m_character.size() == 1)
	//{
	//	for (std::size_t i = 0; i < m_character.size(); i++)
	//	{
	//		std::cout << m_character[i] << " ";
	//	}
	//	std::cout << std::endl;
	//}
	
	
	if (m_character.size() == 2)
	{
		if (m_listening)
		{
			m_receivedMessage = false;
			if (m_character == flag)
			{
				m_charVect.clear();
				std::cout << "START FLAG" << std::endl;
				m_listening = false;
			}
		}
		else if (m_lastEsc == true)
		{
			m_charVect.push_back(m_character[0]);
			m_charVect.push_back(m_character[1]);
			m_lastEsc == false;
		}
		else if (m_character == escChar)
		{
			m_lastEsc = true;
		}
		else if (m_character == flag)
		{
			std::cout << "SLUT FLAG" << std::endl;
			m_listening = true;
			m_receivedMessage = true;
			m_character.clear();
		}
		else
		{
			m_charVect.push_back(m_character[0]);
			m_charVect.push_back(m_character[1]);
		}

	}
	
}

std::vector<sf::Int16> Decoder::intToBit(std::vector<int> DTMFtones)
{

	std::vector<sf::Int16> vecForCRC;

	for (size_t i = 0; i < DTMFtones.size(); i++)
	{
		std::bitset<4> temp(DTMFtones[i]);
		std::cout << temp << std::endl;
		vecForCRC.push_back(temp[3]);
		vecForCRC.push_back(temp[2]);
		vecForCRC.push_back(temp[1]);
		vecForCRC.push_back(temp[0]);
	}

	/*for (size_t i = 0; i < vecForCRC.size(); i++)
	{
		std::cout << vecForCRC[i];
	}

	std::cout << std::endl;
	std::cout << vecForCRC.size() << std::endl;*/
		
	m_renBitStreng = vecForCRC;

	vecForCRC.erase(vecForCRC.begin(), vecForCRC.begin() + 8);		// For at slette sekvensnummer, så der ikke bliver lavet crc tjek på det også 

    return vecForCRC;
  }
 


std::vector<sf::Int16> Decoder::CRCmodtaget(int antal_bit, std::vector<sf::Int16> bitStreng)
{
		
	std::vector<sf::Int16> messageInBit; 

	std::bitset<64> generator2(0b00100000111);
	int DataInsert = antal_bit + 8 - 1;
	int bitStrengSize = bitStreng.size(); //16
	
	int paddingCoeff2 = 0;
	int tjek = bitStrengSize % (antal_bit + 8); // 16


	while (tjek != 0)
	{
		bitStrengSize += 8;						//24 32 40
		tjek = bitStrengSize % (antal_bit + 8);
		paddingCoeff2++;						//1 2 3
	}

	int numPadding2 = (paddingCoeff2) * 8;	//24

	for (int i = 0; i < numPadding2; i++)
	{
		bitStreng.insert(bitStreng.begin(), 0);
	}

	std::cout << "størrelse på bitsteng før crc " << bitStreng.size() << std::endl;

	for (size_t k = 0; k < bitStreng.size(); k += antal_bit + 8) //k=8    vecForCRC = 64
	{
		 
		std::bitset<64> bitMedPadding(0b0);

		for (int i = 0; i < (antal_bit + 8); i++)
		{
			if (bitStreng[i + k] == 1)
			{
				bitMedPadding.set((antal_bit + 8) - 1 - i, 1);
			}
			else
			{
				bitMedPadding.set((antal_bit + 8) - 1 - i, 0);
			}
		}
		
		std::cout << "Streng der er padding på der skal fjernes: ";
		std::vector<int> temp;
		for (size_t i = 0; i < antal_bit; i++)
		{
			temp.push_back(bitMedPadding[i+8]);
			std::cout << temp[i];
		}
		std::cout << std::endl; 
		

		std::reverse(std::begin(temp), std::end(temp));

		for (int i = 0; i < antal_bit; i++)
		{
			if (bitMedPadding[DataInsert - i] == 1)
			{
				bitMedPadding[DataInsert - i] = bitMedPadding[DataInsert - i] xor generator2[8];
				bitMedPadding[DataInsert - 1 - i] = bitMedPadding[DataInsert - 1 - i] xor generator2[7];
				bitMedPadding[DataInsert - 2 - i] = bitMedPadding[DataInsert - 2 - i] xor generator2[6];
				bitMedPadding[DataInsert - 3 - i] = bitMedPadding[DataInsert - 3 - i] xor generator2[5];
				bitMedPadding[DataInsert - 4 - i] = bitMedPadding[DataInsert - 4 - i] xor generator2[4];
				bitMedPadding[DataInsert - 5 - i] = bitMedPadding[DataInsert - 5 - i] xor generator2[3];
				bitMedPadding[DataInsert - 6 - i] = bitMedPadding[DataInsert - 6 - i] xor generator2[2];
				bitMedPadding[DataInsert - 7 - i] = bitMedPadding[DataInsert - 7 - i] xor generator2[1];
				bitMedPadding[DataInsert - 8 - i] = bitMedPadding[DataInsert - 8 - i] xor generator2[0];
			}
		}


		if (bitMedPadding == false)
		{
			std::cout << "Data der blev sendt var det rigtige" << std::endl;
			std::cout << "Sidste besked i bit: ";
			for (size_t i = numPadding2; i < (temp.size() ) ; i++)
			{
				messageInBit.push_back(temp[i]);
				m_CRCok = true;
			}
			
		}
		else
		{
			std::cout << "Der er fejl i beregningen til CRC tjek." << std::endl;
			m_CRCok = false; 
		}
			
		 
	}
	
	return messageInBit;
}

std::string Decoder::decodeMessage()
{
	auto bitstring = intToBit(m_charVect);
	auto CRCModtaget = CRCmodtaget(g_antalbit, bitstring);
	auto String = bitToString(CRCModtaget);
	return String;
}


std::string Decoder::bitToString(std::vector<sf::Int16> messageInBit)
{
	std::string message;
	for (size_t u = 0; u < messageInBit.size(); u += 8)
	{
		std::bitset<8> temp;
		for (size_t i = 0; i < 8; i++)
		{
			if (messageInBit[i + u] == 1)
				temp.set(7 - i, 1);
			else
				temp.set(7 - i, 0);
		}

		int tempi = temp.to_ulong();
		char tempc = (char)tempi;
		message.push_back(tempc);

	}
	return message;
}


