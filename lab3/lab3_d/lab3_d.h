#pragma once
#include <string>

using namespace std;

class Persona {
public:
	string name;
	int age;
public:
	virtual void print() = 0;
	virtual int who() = 0;
	virtual int ask() = 0;
};

class Prepod : public Persona {
public:
	string subject;
	int degree;
public:
	void print() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Subject: " << subject << endl;
		cout << "Degree: ";
		if (degree == 1)
			cout << "CTS";
		else if (degree == 2)
			cout << "DTS";
		else
			cout << "No";
		cout << endl;
		cout << "\n";
	}
	int who() {
		return 1;
	}
	int ask() {
		return degree;
	}
};

class Zav_kaf : public Persona {
public:
	string position;
public:
	void print() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Position: " << position << endl;
		cout << "\n";
	}
	int who() {
		return 2;
	}
	int ask() {
		return age;
	}
};

class Student : public Persona {
public:
	int* marks;
public:
	void print() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Marks: ";
		for (int i = 0; i < 5; i++)
			cout << marks[i] << " ";
		cout << endl;
		cout << "\n";
	}
	int who() {
		return 3;
	}
	int ask() {
		int temp = 0;
		for (int i = 0; i < 5; i++)
			if (marks[i] == 2)
				temp++;
		return temp;
	}
};

class Vuz {
public:
	Prepod* prepods;
	Zav_kaf* zav_kafs;
	Student* students;
	int prepods_n;
	int zav_kafs_n;
	int students_n;
public:
	void print_all() {
		for (int i = 0; i < prepods_n; i++)
			prepods[i].print();
		for (int i = 0; i < zav_kafs_n; i++)
			zav_kafs[i].print();
		for (int i = 0; i < students_n; i++)
			students[i].print();
	}
	void print_request() {
		cout << "Prepods that younger than 50:\n\n";
		for (int i = 0; i < prepods_n; i++)
			if (prepods[i].age < 50)
				prepods[i].print();
		cout << "Students that have bad marks:\n\n";
		for (int i = 0; i < students_n; i++)
			if (students[i].ask() > 0)
				students[i].print();
	}
};

