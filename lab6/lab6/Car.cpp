#include "lab6.h"
#include <iostream>
#include <string>
#include <iomanip>

Car::Car() {
	brand = "";
	number = "";
	year = 0;
	price = 0;
}

void Car::SetInfo(string& brand, string& number, int& year, int& price) {
	this->brand = brand;
	this->number = number;
	this->year = year;
	this->price = price;
}

void Car::Show() {
	cout << setw(9) << brand;
	cout << setw(9) << number;
	cout << setw(9) << year;
	cout << setw(9) << price << "$\n";
}

void Car::Sort(Car* obj, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (obj[j].brand > obj[j + 1].brand)
				swap(obj[j], obj[j + 1]);
}


