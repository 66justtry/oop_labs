#include "lab10_d.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

void Train::SetDest(string temp) {
	this->dest = temp;
}

void Train::SetNumber(int temp) {
	this->number = temp;
}

void Train::SetTime(double temp) {
	this->time = temp;
}

string Train::GetDest() {
	return this->dest;
}

int Train::GetNumber() {
	return this->number;
}

double Train::GetTime() {
	return this->time;
}

void Train::ShowData() {
	cout << setw(8) << "Number" << setw(15) << "Destination" << setw(6) << "Time" << endl;
	cout << "----------------------------------------\n";
	for (int i = 0; i < 5; i++) {
		cout << setw(8) << this[i].number;
		cout << setw(15) << this[i].dest;
		cout << setw(6) << this[i].time;
		cout << endl;
	}
}

int Train::FindTrain(int num) {
	for (int i = 0; i < 5; i++) {
		if (this[i].number == num) {
			return i;
		}
	}
	return -1;
}

void Train::SortNumber() {
	Train temp;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4 - i; j++) {
			if (this[j].number > this[j + 1].number) {
				temp = this[j];
				this[j] = this[j + 1];
				this[j + 1] = temp;
			}
		}
}

void Train::SortDest() {
	Train temp;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4 - i; j++) {
			if (this[j].dest > this[j + 1].dest) {
				temp = this[j];
				this[j] = this[j + 1];
				this[j + 1] = temp;
			}
			else if (this[j].dest == this[j + 1].dest) {
				if (this[j].time > this[j + 1].time) {
					temp = this[j];
					this[j] = this[j + 1];
					this[j + 1] = temp;
				}
			}
		}
}