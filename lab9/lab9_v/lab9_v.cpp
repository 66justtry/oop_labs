#include "lab9_v.h"
#include <iostream>
#include <string>
using namespace std;

bool operator> (const Person& obj1, const Person& obj2) {
	if (obj1.name > obj2.name)
		return true;
	else
		return false;
}