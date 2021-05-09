#include <iomanip>

#include "rrData.h"

namespace rr
{
	void Data::DataAdd(Data& obj2)
	{
		avgC += obj2.avgC;
		p1Wins += obj2.p1Wins;
		p2Wins += obj2.p2Wins;
	}

	void Data::addData(int x)
	{
		avgC += x;

		if (x % 2 == 0)
		{
			p2Wins++;
		}
		else
		{
			p1Wins++;
		}
	}

	void Data::calc(float maxC)
	{
		avg = avgC / maxC;

		percentage1 = (p1Wins / maxC) * 100;
		percentage2 = 100 - percentage1;
	}

	bool Data::outData()
	{
		file.open("sim_final_data.txt", std::ios::out);

		if (!file.is_open())
		{
			std::cout << "File sim_final_data.txt could not be created!" << std::endl;
			return 1;
		}

		int x;
		if (avg < 10)
		{
			x = 1;
		}
		else
		{
			x = 2;
		}

		file << "Average number of rounds played were: " << std::setprecision(x) << avg << " rounds." << std::endl;
		file << "Player 1 won " << std::setprecision(4) << percentage1 << "% of the time." << std::endl;
		file << "Player 2 won " << std::setprecision(4) << percentage2 << "% of the time." << std::endl;

		file.close();
		return 0;
	}
}