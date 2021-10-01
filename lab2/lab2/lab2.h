#pragma once
#include <string>
#define N 5

using namespace std;

class Project {
private:
	int year;
	string name;
	int diameter;
	int frequency;
public:
	Project();
	Project(int, string, int, int);
	void SetYear(int);
	void SetName(string);
	void SetDiameter(int);
	void SetFrequency(int);
	int GetYear();
	string GetName();
	int GetDiameter();
	int GetFrequency();
	friend void DataIn(Project*);
	friend void Show(Project*);
	Project operator = (const Project&);
	Project operator () (int, string, int, int);
	char operator [] (int);
	friend Project operator+ (const Project& obj1, const Project& obj2);
	friend bool operator== (const Project& obj1, const Project& obj2);
	friend ostream& operator<< (ostream& out, const Project& obj);
	friend istream& operator>> (istream& in, Project& obj);
	/*
	Project operator + (const Project&);
	bool operator == (const Project&);
	bool operator != (const Project&);
	void operator >> (Project*);
	void operator << (Project*);
	*/
};

void ShowHeader();

void Show(Project*);

void DataIn(Project*);

void menu(Project*);