#include "lab7_g.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

DB::DB() {
	this->n = 0;
}

DB::DB(int n) {
	this->n = n;
	this->database = new Project[n];
}

DB::~DB() {
	delete[] database;
}

void DB::Add(Project &obj) {
	if (n == 0) {
		database = new Project[1];
		database[0] = obj;
		n++;
	}
	else {
		Project* temp = new Project[n + 1];
		for (int i = 0; i < n; i++)
			temp[i] = database[i];
		temp[n] = obj;
		n++;
		delete[] database;
		database = temp;
	}
}

void DB::Show() {
	cout << "Extraterrestrial Signal Projects\n";
	cout << "----------------------------------------------------------\n";
	cout << " Year | Supervisor | Antenna diameter | Working frequency \n";
	cout << "----------------------------------------------------------\n";
	for (int i = 0; i < n; i++)
		cout << database[i];
}

void DB::SaveToFile(string file, Project& obj) {
	try {
		ofstream out(file, ios::app | ios::ate);
		if (!out.is_open())
			throw "Can't open this file!";
		out << endl << obj.year << " " << obj.name << " " << obj.diameter << " " << obj.frequency;
		out.close();
	}
	catch (string msg) {
		cout << msg << endl;
	}
}

Project DB::ReadFromFile(string file, int num) {
	ifstream in(file);
	try {
		if (!in.is_open())
			throw "Can't open this file!";
	}
	catch (string msg) {
		cout << msg << endl;
	}
	Project temp;
	for (int i = 0; i < num + 1; i++) {
		in >> temp.year >> temp.name >> temp.diameter >> temp.frequency;
	}
	in.close();
	return temp;
}

void DB::SaveToFileAll(string file) {
	ofstream out(file);
	try {
		if (!out.is_open())
			throw "Can't open this file!";
	}
	catch (string msg) {
		cout << msg << endl;
	}
	for (int i = 0; i < n; i++) {
		out << database[i].year << " " << database[i].name << " " << database[i].diameter << " " << database[i].frequency;
		if (i != n - 1)
			out << endl;
	}
	out.close();
}

void DB::ReadFromFileAll(string file) {
	ifstream in(file);
	try {
		if (!in.is_open())
			throw "Can't open this file!";
	}
	catch (string msg) {
		cout << msg << endl;
	}
	Project temp;
	int num = 0;
	for (;;) {
		if (in.eof())
			break;
		else {
			in >> temp.year >> temp.name >> temp.diameter >> temp.frequency;
			num++;
		}
	}
	if (num == 0) {
		in.close();
		return;
	}
	/*if (file == "default.txt")
		n = num;
	else if (file == "text.txt")
		n = num - 1;*/
	n = num;
	delete[] database;
	database = new Project[n];
	in.seekg(0, ios::beg);
	for (int i = 0; i < n; i++) {
		in >> database[i].year >> database[i].name >> database[i].diameter >> database[i].frequency;
	}

	in.close();
}

Project& DB::Getline(int num) {
	try {
		if (num >= n)
			throw "Can't find a line with this number!";
	}
	catch (string msg) {
		cout << msg << endl;
	}
	return database[num];
}

void DB::Setline(int num, int year, string name, int diameter, int frequency) {
	if (num >= n)
		return;
	database[num].year = year;
	database[num].name = name;
	database[num].diameter = diameter;
	database[num].frequency = frequency;
}