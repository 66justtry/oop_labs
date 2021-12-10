#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person {
	string name;
	int age;
public:
	Person();
	Person(string);
	Person(int);
	string GetName();
	int GetAge();
	friend bool operator> (const Person& obj1, const Person& obj2);
};

class Compare {
	bool operator() ();
};

class Staff {
	map<Person, Person> list;
public:
	void Insert();
	void Show();
	void ShowName();
	void ShowAge();
	void Delete();
	void Add();
	void FindName();
	void FindAge();
};