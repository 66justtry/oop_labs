#pragma once
#include <iostream>
#include <string>

using namespace std;

class Car {
private:
	string brand;
	string number;
	int year;
	int price;
public:
	Car();
	void Show();
	void SetInfo(string&, string&, int&, int&);
	void static Sort(Car*, int);
};

void Show(Car*, int);

void DataIn(Car*, int);
