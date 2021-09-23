#include "lab11_e.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void menu(Time obj1, Time obj2) {
	int ch;
	system("cls");
	cout << "time1: ";
	obj1.Show();
	cout << endl;
	cout << "time2: ";
	obj2.Show();
	cout << "\n\n";
	cout << "1 - Compare 2 times\n";
	cout << "2 - Get degree\n";
	cout << "3 - Exit\n";
	cin >> ch;
	if (ch == 1) {
		system("cls");
		cout << "time1: ";
		obj1.Show();
		cout << endl;
		cout << "time2: ";
		obj2.Show();
		cout << "\n\n";
		Time::Difference(obj1, obj2);
		system("pause");
	}
	else if (ch == 2) {
		int q;
		system("cls");
		cout << "time1: ";
		obj1.Show();
		cout << endl;
		cout << "time2: ";
		obj2.Show();
		cout << "\n\n";
		cout << "\nDegree of object 1 = " << obj1.GetDegree() << endl;
		cout << "\nDegree of object 2 = " << obj2.GetDegree() << endl;
		system("pause");
	}
	else if (ch == 3) {
		exit(0);
	}
	menu(obj1, obj2);
}

int main() {
	Time obj1, obj2;
	cout << "Create 2 objects Time:\n\n";
	Time& ref1 = obj1;
	Time& ref2 = obj2;
	SetData(ref1);
	SetData(ref2);
	menu(obj1, obj2);
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