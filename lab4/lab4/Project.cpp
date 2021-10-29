#include "lab4.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
Project::Project() {
	this->year = 0;
	this->name = "unknown";
	this->diameter = 0;
	this->frequency = 0;
}
Project::Project(int year, string name, int diameter, int frequency) {
	this->year = year;
	this->name = name;
	this->diameter = diameter;
	this->frequency = frequency;
}
void Project::SetYear(int a) {
	year = a;
}
void Project::SetName(string a) {
	name = a;
}
void Project::SetDiameter(int a) {
	diameter = a;
}
void Project::SetFrequency(int a) {
	frequency = a;
}
int Project::GetYear() {
	return this->year;
}
string Project::GetName() {
	return this->name;
}
int Project::GetDiameter() {
	return this->diameter;
}
int Project::GetFrequency() {
	return this->frequency;
}

Project Project::operator = (const Project& obj) {
	year = obj.year;
	name = obj.name;
	diameter = obj.diameter;
	frequency = obj.frequency;
	return *this;
}

Project Project::operator () (int a, string b, int c, int d) {
	year = a;
	name = b;
	diameter = c;
	frequency = d;
	return *this;
}

char Project::operator [] (int i) {
	char q;
	if (name.size() < i)
		q = '0';
	else
		q = name[i];
	return q;
}


//Project Project::operator + (const Project& obj) {
//	Project temp;
//	temp.year = year + obj.year;
//	temp.name = name + obj.name;
//	temp.diameter = diameter + obj.diameter;
//	temp.frequency = frequency + obj.frequency;
//	return temp;
//}
//bool Project::operator == (const Project& obj) {
//	if ((year == obj.year) && (name == obj.name) && (diameter == obj.diameter) && (frequency == obj.frequency))
//		return true;
//	else
//		return false;
//}
//bool Project::operator != (const Project& obj) {
//	if ((year == obj.year) && (name == obj.name) && (diameter == obj.diameter) && (frequency == obj.frequency))
//		return false;
//	else
//		return true;
//}
//void Project::operator >> (Project* arr) {
//	ifstream in;
//	in.open("in.txt");
//	for (int i = 0; i < N; i++)
//		if (in.is_open())
//			in >> arr[i].year >> arr[i].name >> arr[i].diameter >> arr[i].frequency;
//	in.close();
//}
//void Project::operator << (Project* arr) {
//	ofstream out;
//	out.open("out.txt");
//	for (int i = 0; i < N; i++)
//		if (out.is_open()) {
//			out << arr[i].year << " " << arr[i].name << " " << arr[i].diameter << " " << arr[i].frequency << endl;
//		}
//	out.close();
//}


