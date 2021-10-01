#include "lab2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	Project* project = new Project[N];
	DataIn(project);
	menu(project);
	system("pause");
	delete[] project;
}

void DataIn(Project* arr) {
	ifstream in;
	in.open("in.txt");
	for (int i = 0; i < N; i++)
		if (in.is_open())
			in >> arr[i];
			//in >> arr[i].year >> arr[i].name >> arr[i].diameter >> arr[i].frequency;
	in.close();
}

void Show(Project* arr) {
	for (int i = 0; i < N; i++)
		cout << arr[i];
}

void ShowHeader() {
	system("cls");
	cout << "Extraterrestrial Signal Projects\n";
	cout << "----------------------------------------------------------\n";
	cout << " Year | Supervisor | Antenna diameter | Working frequency \n";
	cout << "----------------------------------------------------------\n";
}

Project operator+ (const Project& obj1, const Project& obj2) {
	Project temp;
	temp.SetYear(obj1.year + obj2.year);
	temp.SetName(obj1.name + obj2.name);
	temp.SetDiameter(obj1.diameter + obj2.diameter);
	temp.SetFrequency(obj1.frequency + obj2.frequency);
	return temp;
}

bool operator== (const Project& obj1, const Project& obj2) {
	if ((obj1.year == obj2.year) && (obj1.name == obj2.name) && (obj1.diameter == obj2.diameter) && (obj1.frequency == obj2.frequency))
		return true;
	else
		return false;
}

ostream& operator<< (ostream& out, const Project& obj) {
	out << setw(5) << obj.year << setw(13) << obj.name << setw(13) << obj.diameter << setw(20) << obj.frequency << endl;
	return out;
}

istream& operator>> (istream& in, Project& obj) {
	in >> obj.year;
	in >> obj.name;
	in >> obj.diameter;
	in >> obj.frequency;
	return in;
}

void menu(Project* project) {
	int ch;
	system("cls");
	ShowHeader();
	Show(project);
	cout << "\n\n1 - Create a copy of a line\n";
	cout << "2 - Add a line to another one\n";
	cout << "3 - Compare 2 lines\n";
	cout << "4 - Change a line (operator >> )\n";
	cout << "5 - Change a line (operator () )\n";
	cout << "6 - Get a symbol from name\n";
	cout << "7 - Exit\n";
	cin >> ch;
	if (ch == 1) {
		int x, y;
		cout << "line 1: ";
		cin >> x;
		cout << "line 2: ";
		cin >> y;
		x--;
		y--;
		project[x] = project[y];
	}
	else if (ch == 2) {
		int x, y;
		cout << "line 1: ";
		cin >> x;
		cout << "line 2: ";
		cin >> y;
		x--;
		y--;
		project[x] = project[x] + project[y];
	}
	else if (ch == 3) {
		int x, y;
		cout << "line 1: ";
		cin >> x;
		cout << "line 2: ";
		cin >> y;
		x--;
		y--;
		if (project[x] == project[y])
			cout << "line 1 == line 2\n";
		else
			cout << "line 1 != line 2\n";
	}
	else if (ch == 4) {
		int x;
		cout << "line: ";
		cin >> x;
		x--;
		cout << "Enter year, name, diameter, frequency:\n";
		cin >> project[x];
		//project[x](year, name, diameter, frequency);
	}
	else if (ch == 5) {
		int x;
		int year, diameter, frequency;
		string name;
		cout << "\nline: ";
		cin >> x;
		x--;
		cout << "year: ";
		cin >> year;
		cout << "name: ";
		cin >> name;
		cout << "diameter: ";
		cin >> diameter;
		cout << "frequency: ";
		cin >> frequency;
		project[x](year, name, diameter, frequency);
	}
	else if (ch == 6) {
		int x, y;
		cout << "line: ";
		cin >> x;
		x--;
		cout << "number of symbol in string: ";
		cin >> y;
		y--;
		cout << endl << project[x][y] << endl;
	}
	else if (ch == 7)
		exit(0);
	system("pause");
	menu(project);
}