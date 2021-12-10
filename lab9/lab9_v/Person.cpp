#include "lab9_v.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person() {
	name = "unknown";
	age = 0;
}
Person::Person(string x) {
	name = x;
	age = 0;
}
Person::Person(int x) {
	name = "unknown";
	age = x;
}
string Person::GetName() {
	return name;
}
int Person::GetAge() {
	return age;
}
bool Compare::operator() () {
	if ()
}