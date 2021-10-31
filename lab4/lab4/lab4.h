#pragma once
#include <string>

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
	Project operator = (const Project&);
	Project operator () (int, string, int, int);
	char operator [] (int);
	friend Project operator+ (const Project& obj1, const Project& obj2);
	friend bool operator== (const Project& obj1, const Project& obj2);
	friend ostream& operator<< (ostream& out, const Project& obj);
	friend istream& operator>> (istream& in, Project& obj);
	friend class DB;
};

class DB {
public:
	Project* ptr;
	bool sorted;
	int n;
public:
	DB();
	void DataIn();
	void Show();
	void Sort();
	void Delete();
	void Add(int, string, int, int);
	friend class Project;
};

void menu(DB*);