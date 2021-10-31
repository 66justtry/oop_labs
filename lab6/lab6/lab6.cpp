#include "lab6.h"
#include <iostream>
#include <fstream>

using namespace std;

void menu(Car* obj, int n) {
	system("cls");
	Show(obj, n);
	cout << "\n\n";
	int ch;
	cout << "1 - Get a database from file\n";
	cout << "2 - Change a line\n";
	cout << "3 - Sort the database\n";
	cout << "4 - Exit\n";
	cin >> ch;
	if (ch == 1) {
		DataIn(obj, n);
	}
	else if (ch == 2) {
		string brand, number;
		int year, price;
		string& pbrand = brand;
		string& pnumber = number;
		int& pyear = year;
		int& pprice = price;
		int x;
		cout << "line: ";
		cin >> x;
		x--;
		cout << "brand: ";
		cin >> brand;
		cout << "number: ";
		cin >> number;
		cout << "year: ";
		cin >> year;
		cout << "price: ";
		cin >> price;
		obj[x].SetInfo(pbrand, pnumber, pyear, pprice);
	}
	else if (ch == 3) {
		Car::Sort(obj, n);
	}
	else if (ch == 4) {
		return;
	}
	system("pause");
	menu(obj, n);
}

void Show(Car* obj, int n) {
	cout << "\n  Brand  |  Number  |  Year  |  Price\n";
	cout << "--------------------------------------\n";
	for (int i = 0; i < n; i++)
		obj[i].Show();
}

void DataIn(Car* obj, int n) {
	string brand, number;
	string& pbrand = brand;
	string& pnumber = number;
	int year, price;
	int& pyear = year;
	int& pprice = price;
	ifstream in;
	in.open("in.txt");
	for (int i = 0; i < n; i++) {
		in >> brand >> number >> year >> price;
		obj[i].SetInfo(pbrand, pnumber, pyear, pprice);
	}
	in.close();
}

int main() {
	int n = 5;
	Car* cars = new Car[n];
	menu(cars, n);
	delete[] cars;
	return 0;
}