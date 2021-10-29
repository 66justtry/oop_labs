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
};

class DB {
private:
	Project* ptr;
	bool sorted;
public:
	void DataIn();
	void Show();
	void Sort();
	void Delete();
	void Add();
	friend class Project;
};

void menu(Project*);