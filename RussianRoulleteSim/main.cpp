#include <iostream>
#include <ostream>
#include <cstdlib>
#include <time.h>
#include <thread>

#include "rrData.h"

#define MAX_COUNT_ 1000000000

#define NUM_OF_THREADS 10
#define BASE_SEED 374

#define COUNT_PER_THREAD (MAX_COUNT_ / NUM_OF_THREADS)

#define SEED (BASE_SEED + NUM_OF_THREADS)

bool check1 = true;
bool check2 = true;
bool check3 = true;
bool check4 = true;
bool check5 = true;
bool check6 = true;
bool check7 = true;
bool check8 = true;
bool check9 = true;
bool check10 = true;

void run(rr::Data& data, int x, bool& check)
{
	srand(SEED + x);

	int count = 0;

	while (count < COUNT_PER_THREAD)
	{
		int numRounds = 0;
		short shotVal = 0;
		bool temp = true;

		while (temp)
		{
			numRounds++;
			for (int i = 0; i < numRounds; i++)
			{
				shotVal = (rand() % 6) + 1;
				if (shotVal == 3)
				{
					data.addData(numRounds);
					temp = false;
					break;
				}
			}
		}
		count++;
	}

	check = false;
	return;
}

int main()
{
	srand(time(NULL));
	int count = 0;
	rr::Data data;

	rr::Data* data1 = new rr::Data;
	rr::Data* data2 = new rr::Data;
	rr::Data* data3 = new rr::Data;
	rr::Data* data4 = new rr::Data;
	rr::Data* data5 = new rr::Data;
	rr::Data* data6 = new rr::Data;
	rr::Data* data7 = new rr::Data;
	rr::Data* data8 = new rr::Data;
	rr::Data* data9 = new rr::Data;
	rr::Data* data10 = new rr::Data;

	std::fstream file;
	
	file.open("raw_data.txt", std::ios::out);

	if (!file.is_open())
	{
		std::cout << "File raw_data.txt could not be created!" << std::endl;
		return 1;
	}

	file << "Raw Data disabled!";
	file.close();

	std::thread Thread1(run, std::ref(*data1), 0, std::ref(check1));
	std::thread Thread2(run, std::ref(*data2), 1, std::ref(check2));
	std::thread Thread3(run, std::ref(*data3), 2, std::ref(check3));
	std::thread Thread4(run, std::ref(*data4), 3, std::ref(check4));
	std::thread Thread5(run, std::ref(*data5), 4, std::ref(check5));
	std::thread Thread6(run, std::ref(*data6), 5, std::ref(check6));
	std::thread Thread7(run, std::ref(*data7), 6, std::ref(check7));
	std::thread Thread8(run, std::ref(*data8), 7, std::ref(check8));
	std::thread Thread9(run, std::ref(*data9), 8, std::ref(check9));
	std::thread Thread10(run, std::ref(*data10), 9, std::ref(check10));
	
	Thread1.detach();
	Thread2.detach();
	Thread3.detach();
	Thread4.detach();
	Thread5.detach();
	Thread6.detach();
	Thread7.detach();
	Thread8.detach();
	Thread9.detach();
	Thread10.detach();

	while (check1 && check2 && check3 && check4 && check5 && check6 && check7 && check8 && check9 && check10)
	{
		
	}

	data.DataAdd(data, *data1);
	data.DataAdd(data, *data2);
	data.DataAdd(data, *data3);
	data.DataAdd(data, *data4);
	data.DataAdd(data, *data5);
	data.DataAdd(data, *data6);
	data.DataAdd(data, *data7);
	data.DataAdd(data, *data8);
	data.DataAdd(data, *data9);
	data.DataAdd(data, *data10);

	delete data1;
	delete data2;
	delete data3;
	delete data4;
	delete data5;
	delete data6;
	delete data7;
	delete data8;
	delete data9;
	delete data10;


	data.calc(MAX_COUNT_);
	
	if (data.outData())
	{
		return 1;
	}
	
	std::cout << "Simulation complete and data files have been written!" << std::endl;
	return 0;
}
