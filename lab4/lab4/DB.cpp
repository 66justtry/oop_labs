#include "lab4.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void DB::DataIn() {
	ifstream in;
	in.open("in.txt");
	for (int i = 0; i < N; i++)
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
	for (int i = 0; i < N; i++)
		cout << ptr[i];
}