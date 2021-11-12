#pragma once
#include <iostream>
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
	friend class DB;
	Project operator= (const Project&);
	friend ostream& operator<< (ostream&, const Project&);
};

class DB {
private:
	int n;
	Project* database;
public:
	DB();
	DB(int);
	~DB();
	Project& Getline(int);
	void Setline(int, int, string, int, int);
	void Add(Project&);
	void Show();
	void SaveToFile(string, Project&);
	Project ReadFromFile(string, int);
	void SaveToFileAll(string);
	void ReadFromFileAll(string);
};

void menu(DB*);
