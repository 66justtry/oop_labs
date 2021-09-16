#include "lab2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	Project* project = new Project[N];
	project[0] >> project;
	ShowHeader();
	Show(project);
	project[0] << project;
	system("pause");
	system("cls");
	project[4] = project[0] + project[1];
	project[3] = project[2];
	ShowHeader();
	Show(project);
	if (project[2] == project[3])
		cout << "project[2] = project[3]\n";
	system("pause");
}

void DataIn(Project* arr) {
	ifstream in;
	in.open("txt.txt");
	for (int i = 0; i < N; i++)
		if (in.is_open())
			in >> arr[i].year >> arr[i].name >> arr[i].diameter >> arr[i].frequency;
	in.close();
}

void Show(Project* arr) {
	for (int i = 0; i < N; i++)
		cout << setw(5) << arr[i].year << setw(13) << arr[i].name << setw(19) << arr[i].diameter << setw(20) << arr[i].frequency << endl;
}

void ShowHeader() {
	system("cls");
	cout << "Extraterrestrial Signal Projects\n";
	cout << "----------------------------------------------------------\n";
	cout << " Year | Supervisor | Antenna diameter | Working frequency \n";
	cout << "----------------------------------------------------------\n";
}