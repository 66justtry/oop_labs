#pragma once
#include <string>

using namespace std;

class Train {
private:
	string dest;
	int number;
	double time;
public:
	void SetDest(string);
	void SetNumber(int);
	void SetTime(double);
	string GetDest();
	int GetNumber();
	double GetTime();
	void ShowData();
	int FindTrain(int);
	void SortNumber();
	void SortDest();
	Train() : dest("unknown"), number(0), time(00.00) {}
};


