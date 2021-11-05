#include "lab4.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

DB::DB() {
	n = 5;
	ptr = new Project[n];
	sorted = false;
}

void DB::DataIn() {
	ifstream in;
	in.open("in.txt");
	for (int i = 0; i < n; i++)
		if (in.is_open())
			in >> ptr[i];
	in.close();
}

void DB::Show() {
	system("cls");
	cout << "Extraterrestrial Signal Projects\n";
	cout << "----------------------------------------------------------\n";
	cout << " Year | Supervisor | Antenna diameter | Working frequency \n";
	cout << "----------------------------------------------------------\n";
	for (int i = 0; i < n; i++)
		cout << ptr[i];
}

void DB::Sort() {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (ptr[j].year < ptr[j + 1].year) {
				swap(ptr[j], ptr[j + 1]);
			}
	sorted = true;
}

void DB::Add(int year, string name, int diameter, int frequency) {
	Project* temp = new Project[n + 1];
	for (int i = 0; i < n; i++) {
		temp[i] = ptr[i];
	}
	temp[n](year, name, diameter, frequency);
	n++;
	delete[] ptr;
	ptr = temp;
}

void DB::Delete() {
	if (n == 0)
		return;
	Project* temp = new Project[n - 1];
	for (int i = 0; i < (n - 1); i++)
		temp[i] = ptr[i];
	n--;
	delete[] ptr;
	ptr = temp;
}