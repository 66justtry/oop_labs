#include "lab10_d.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

Train trains[5];

void menu() {
	int ch;
	system("cls");
	trains->ShowData();
	cout << "\n1 - Find the train by number\n";
	cout << "2 - Sort the trains by destination column\n";
	cout << "3 - Sort the trains by numbers of trains\n";
	cout << "4 - Exit\n";
	cin >> ch;
	if (ch == 1) {
		int num;
		system("cls");
		cout << "Enter the number of train you're looking for: ";
		cin >> num;
		int x = trains->FindTrain(num);
		if (x == -1)
			cout << "Sorry, the train with this number does not exist :(\n";
		else {
			cout << setw(8) << "Number" << setw(15) << "Destination" << setw(6) << "Time" << endl;
			cout << "----------------------------------------\n";
			cout << setw(8) << trains[x].GetNumber();
			cout << setw(15) << trains[x].GetDest();
			cout << setw(6) << trains[x].GetTime();
			cout << endl;
		}
		system("pause");
	}
	else if (ch == 2) {
		system("cls");
		trains->SortDest();
		trains->ShowData();
		system("pause");
	}
	else if (ch == 3) {
		system("cls");
		trains->SortNumber();
	}
	else if (ch == 4)
		exit(0);
	menu();
}

int main() {
	string dest;
	int num;
	double time;
	ifstream in;
	in.open("txt.txt");
	for (int i = 0; i < 5; i++) {
		if (in.is_open()) {
			/*system("cls");
			cout << "Enter the information about 5 trains\n\n";
			cout << "Destination: ";
			cin >> dest;
			trains[i].SetDest(dest);
			cout << "Number: ";
			cin >> num;
			trains[i].SetNumber(num);
			cout << "Time: ";
			cin >> time;
			trains[i].SetTime(time);*/
			in >> num >> dest >> time;
			trains[i].SetNumber(num);
			trains[i].SetDest(dest);
			trains[i].SetTime(time);
		}
	}
	trains->SortNumber();
	menu();

	return 0;
}

