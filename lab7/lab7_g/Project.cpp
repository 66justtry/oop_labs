#include "lab7_g.h"
#include <iostream>
#include <string>

using namespace std;

Project::Project() {
	year = 0;
	name = "";
	diameter = 0;
	frequency = 0;
}

Project::Project(int year, string name, int diameter, int frequency) {
	this->year = year;
	this->name = name;
	this->diameter = diameter;
	this->frequency = frequency;
}

Project Project::operator = (const Project& obj) {
	year = obj.year;
	name = obj.name;
	diameter = obj.diameter;
	frequency = obj.frequency;
	return *this;
}
