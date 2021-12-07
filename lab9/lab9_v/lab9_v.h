#pragma once
#include <iostream>
#include <string>
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
};