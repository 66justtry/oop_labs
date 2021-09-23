#pragma once

class Numbers {
private:
	int n;
	int min;
	int max;
	int* arr;
public:
	Numbers();
	Numbers(int, int, int);
	Numbers(Numbers&, int);
	int GetMin();
	int GetMax();
	void Generate();
	void Show();
	static void Union(Numbers, Numbers);
	static void Crossing(Numbers, Numbers);
	static void Difference(Numbers, Numbers);
	static void DisSum(Numbers, Numbers);
};

void Show(Numbers* numbers);
