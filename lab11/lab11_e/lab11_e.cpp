#include "lab11_e.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void menu() {
	system("cls");
	cout << "";
}

int main() {
	Time obj1, obj2;
	cout << "Create 2 objects Time:\n";
	Time& ref1 = obj1;
	Time& ref2 = obj2;
	SetData(ref1);
	SetData(ref2);
	system("cls");
	cout << "time1: ";
	obj1.Show();
	cout << endl;
	cout << "time2: ";
	obj2.Show();
	cout << "\n\n";
	Time::Difference(obj1, obj2);
	cout << endl;
	cout << "time1's degree: " << obj1.GetDegree();
	cout << "\n\ntime2's degree: " << obj2.GetDegree();
	cout << "\n\n";
	system("pause");
}

void SetData(Time &obj) {
	int temp;
get1:
	cout << "Hour: ";
	cin >> temp;
	if ((temp > 23) || (temp < 0)) {
		cout << "Error!";
		goto get1;
	}
	obj.SetHour(temp);
get2:
	cout << "Minute: ";
	cin >> temp;
	if ((temp > 59) || (temp < 0)) {
		cout << "Error!";
		goto get2;
	}
	obj.SetMinute(temp);
get3:
	cout << "Second: ";
	cin >> temp;
	if ((temp > 59) || (temp < 0)) {
		cout << "Error!";
		goto get3;
	}
	obj.SetSecond(temp);
}