#ifndef DATA_H_
#define DATA_H_

#include <iostream>
#include <fstream>
#include <vector>

namespace rr
{
	class Data
	{
	private:
		std::fstream file;
		int avgC = 0;
		long double avg = 0.0;
		float percentage1 = 0.0f;
		float percentage2 = 0.0f;
		int p1Wins = 0, p2Wins = 0;
	public:
		Data() {}
		void DataAdd(Data& obj1, Data& obj2);
		
		void addData(int x);
		void calc(float maxC);
		bool outData();
	};
}
#endif