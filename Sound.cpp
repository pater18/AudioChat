#include "Sound.h"



customSound::customSound()
{
}

short customSound::Sinewave(double time, double freq1, double freq2, double amp)
{
	const double TWOPI = 6.283185307;
	short result1;
	double tpc1 = 44100 / freq1;
	double cycles1 = time / tpc1;
	double rad1 = TWOPI * cycles1;
	short amplitude = 32767 * amp;
	result1 = amplitude * sin(rad1);

	short result2;
	double tpc2 = 44100 / freq2;
	double cycles2 = time / tpc2;
	double rad2 = TWOPI * cycles2;
	result2 = amplitude * sin(rad2);

	_result = result1 + result2;

	return _result;
}


  


std::vector<sf::Int16> customSound::message(int tid)
{
	std::ofstream dataSound; 
	dataSound.open ("data.txt");

	int freq1, freq2, count = 0;
	double multipleEnd = 0.9, multipleStart = 0;
	double faktor = tid / 2;
	faktor = 0.9 * e^;


	freq1 = 697;
	freq2 = 1209;

	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		if (i < (tid / 2))
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleStart);
			multipleStart += faktor;
		}
		else
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleEnd);
			multipleEnd -= faktor;
		}
	}
	multipleStart = 0;
	multipleEnd = 0.9;

	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		if (i < (tid / 2))
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleStart);
			multipleStart += faktor;
		}
		else
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleEnd);
			multipleEnd -= faktor;
		}
	}

	multipleStart = 0;
	multipleEnd = 0.9;

	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		if (i < (tid / 2))
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleStart);
			multipleStart += faktor;
		}
		else
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleEnd);
			multipleEnd -= faktor;
		}
	}

	multipleStart = 0;
	multipleEnd = 0.9;


	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		if (i < (tid / 2))
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleStart);
			multipleStart += faktor;
		}
		else
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleEnd);
			multipleEnd -= faktor;
		}
	}

	multipleStart = 0;
	multipleEnd = 0.9;


	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		if (i < (tid / 2))
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleStart);
			multipleStart += faktor;
		}
		else
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleEnd);
			multipleEnd -= faktor;
		}
	}

	multipleStart = 0;
	multipleEnd = 0.9;


	for (size_t i = 0; i < 500; i++)
	{
		std::cout << _customSound[_customSound.size() - 500 + i] << " ";
	}
	std::cout << std::endl;


	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		if (i < (tid - (tid * 0.9)))
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5))*multipleStart);
			multipleStart += faktor;
		}
		else if (i < (tid - (tid * 0.10)) && i > tid - (tid * 0.9))
		{
			_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
		}
		else
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleEnd);
			multipleEnd -= faktor;
		}
	}

	multipleEnd = 0.9;
	multipleStart = 0;

	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		if (i < (tid - (tid * 0.9)))
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleStart);
			multipleStart += faktor;
		}
		else if (i < (tid - (tid * 0.10)) && i > tid - (tid * 0.9))
		{
			_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
		}
		else
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleEnd);
			multipleEnd -= faktor;
		}
	}

	multipleEnd = 0.9;
	multipleStart = 0;

	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		if (i < (tid - (tid * 0.9)))
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleStart);
			multipleStart += faktor;
		}
		else if (i < (tid - (tid * 0.10)) && i > tid - (tid * 0.9))
		{
			_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
		}
		else
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleEnd);
			multipleEnd -= faktor;
		}
	}

	multipleEnd = 0.9;
	multipleStart = 0;

	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		if (i < (tid - (tid * 0.9)))
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleStart);
			multipleStart += faktor;
		}
		else if (i < (tid - (tid * 0.10)) && i > tid - (tid * 0.9))
		{
			_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
		}
		else
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleEnd);
			multipleEnd -= faktor;
		}
	}

	multipleEnd = 0.9;
	multipleStart = 0;

	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		if (i < (tid - (tid * 0.9)))
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleStart);
			multipleStart += faktor;
		}
		else if (i < (tid - (tid * 0.10)) && i > tid - (tid * 0.9))
		{
			_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
		}
		else
		{
			_customSound.push_back((customSound::Sinewave(i, freq1, freq2, 0.5)) * multipleEnd);
			multipleEnd -= faktor;
		}
	}


	std::cout << std::endl;

	for (size_t i = 0; i < 500; i++)
	{
		std::cout << _customSound[i + tid] << " ";
	}





	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	}
	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	}
	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	}
	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	}
	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	}
	for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	{
		_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	}



	for (size_t i = 0; i < 500; i++)
	{
		std::cout << _customSound[i] << " ";
	}

	
	for (size_t i = 0; i < 500; i++)
	{
		std::cout << _customSound[i] << " ";
	}
	std::cout << std::endl; 
	
	  
	//freq1 = 697;
	//freq2 = 1209;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	//freq1 = 697;
	//freq2 = 1336;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	//freq1 = 697;
	//freq2 = 1477;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	//freq1 = 697;
	//freq2 = 1633;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	//freq1 = 770;
	//freq2 = 1209;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	//freq1 = 770;
	//freq2 = 1336;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//	dataSound << customSound::Sinewave(i, freq1, freq2, 0.5) << std::endl;
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//	dataSound << customSound::Sinewave(i, freq1, freq2, 0.5) << std::endl;
	//}

	//freq1 = 770;
	//freq2 = 1477;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	//freq1 = 770;
	//freq2 = 1633;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	//freq1 = 852;
	//freq2 = 1209;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	//freq1 = 852;
	//freq2 = 1336;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//	dataSound << customSound::Sinewave(i, freq1, freq2, 0.5) << std::endl;
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//	dataSound << customSound::Sinewave(i, freq1, freq2, 0.5) << std::endl;
	//}

	//freq1 = 852;
	//freq2 = 1477;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	//freq1 = 852;
	//freq2 = 1633;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	//freq1 = 941;
	//freq2 = 1209;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	//freq1 = 941;
	//freq2 = 1336;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	//freq1 = 941;
	//freq2 = 1477;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	//freq1 = 941;
	//freq2 = 1633;
	//for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}
	//for (int i = 1; i < tid; i++)			// 44100 giver lyden i 1 sekund
	//{
	//	_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
	//}

	dataSound.close();

	for (int i = 0; i < _Encoded.size(); i += 4) // 0, 4, 8
	{
		if (((_Encoded[i] == 0)) && (_Encoded[i + 1] == 0) && (_Encoded[i + 2]) == 0 && (_Encoded[i + 3] == 0))				//Bit 0000 = 0
		{
			freq1 = 697;
			freq2 = 1209;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}

		}
		if ((_Encoded[i] == 0) && (_Encoded[i + 1] == 0) && (_Encoded[i + 2] == 0) && (_Encoded[i + 3] == 1))			//Bit 0001 = 1
		{
			freq1 = 697;
			freq2 = 1336;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}

		}
		if ((_Encoded[i] == 0) && (_Encoded[i + 1] == 0) && (_Encoded[i + 2] == 1) && (_Encoded[i + 3] == 0))			//Bit 0010 = 2
		{
			freq1 = 697;
			freq2 = 1477;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
		if ((_Encoded[i] == 0) && (_Encoded[i + 1] == 0) && (_Encoded[i + 2] == 1) && (_Encoded[i + 3] == 1))			//Bit 0011 = 3
		{
			freq1 = 697;
			freq2 = 1633;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
		if ((_Encoded[i] == 0) && (_Encoded[i + 1] == 1) && (_Encoded[i + 2] == 0) && (_Encoded[i + 3] == 0))			//Bit 0100 = 4
		{
			freq1 = 770;
			freq2 = 1209;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
		if ((_Encoded[i] == 0) && (_Encoded[i + 1] == 1) && (_Encoded[i + 2] == 0) && (_Encoded[i + 3] == 1))			//Bit 0101 = 5
		{
			freq1 = 770;
			freq2 = 1336;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
		if ((_Encoded[i] == 0) && (_Encoded[i + 1] == 1) && (_Encoded[i + 2] == 1) && (_Encoded[i + 3] == 0))			//Bit 0110 = 6
		{
			freq1 = 770;
			freq2 = 1477;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
		if ((_Encoded[i] == 0) && (_Encoded[i + 1] == 1) && (_Encoded[i + 2] == 1) && (_Encoded[i + 3] == 1))			//Bit = 7
		{
			freq1 = 770;
			freq2 = 1633;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
		if ((_Encoded[i] == 1) && (_Encoded[i + 1] == 0) && (_Encoded[i + 2] == 0) && (_Encoded[i + 3] == 0))			//Bit 1000 = 8
		{
			freq1 = 852;
			freq2 = 1209;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
		if ((_Encoded[i] == 1) && (_Encoded[i + 1] == 0) && (_Encoded[i + 2] == 0) && (_Encoded[i + 3] == 1))			//Bit = 9
		{
			freq1 = 852;
			freq2 = 1336;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
		if ((_Encoded[i] == 1) && (_Encoded[i + 1] == 0) && (_Encoded[i + 2] == 1) && (_Encoded[i + 3] == 0))			//Bit = 10
		{
			freq1 = 852;
			freq2 = 1477;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
		if ((_Encoded[i] == 1) && _Encoded[i + 1] == 0 && (_Encoded[i + 2] == 1) && (_Encoded[i + 3] == 1))			//Bit = 11
		{
			freq1 = 852;
			freq2 = 1633;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
		if ((_Encoded[i] == 1) && (_Encoded[i + 1] == 1) && (_Encoded[i + 2] == 0) && (_Encoded[i + 3] == 0))			//Bit = 12
		{
			freq1 = 941;
			freq2 = 1209;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
		if ((_Encoded[i] == 1) && (_Encoded[i + 1] == 1) && (_Encoded[i + 2] == 0) && (_Encoded[i + 3] == 1))			//Bit = 13
		{
			freq1 = 941;
			freq2 = 1336;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
		if ((_Encoded[i] == 1) && (_Encoded[i + 1] == 1) && (_Encoded[i + 2] == 1) && (_Encoded[i + 3] == 0))			//Bit = 14
		{
			freq1 = 941;
			freq2 = 1477;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}
		if ((_Encoded[i] == 1) && (_Encoded[i + 1] == 1) && (_Encoded[i + 2] == 1) && (_Encoded[i + 3] == 1))			//Bit = 15
		{
			freq1 = 941;
			freq2 = 1633;
			for (int i = 0; i < tid; i++)			// 44100 giver lyden i 1 sekund
			{
				_customSound.push_back(customSound::Sinewave(i, freq1, freq2, 0.5));
			}
		}

	}


	return _customSound;

}