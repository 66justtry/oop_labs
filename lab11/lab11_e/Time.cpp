#include "lab11_e.h"
#include <iostream>

using namespace std;

int Time::GetHour() {
	return this->hour;
}

int Time::GetMinute() {
	return this->minute;
}

int Time::GetSecond() {
	return this->second;
}

void Time::SetHour(int x) {
	if ((x > 23) || (x < 0))
		return;
	this->hour = x;
}

void Time::SetMinute(int x) {
	if ((x > 59) || (x < 0))
		return;
	this->minute = x;
}

void Time::SetSecond(int x) {
	if ((x > 59) || (x < 0))
		return;
	this->second = x;
}

void Time::Show() {
	cout << hour << ":" << minute << ":" << second << endl;
}

void Time::Difference(Time obj1, Time obj2) {
	/*int temp1 = obj1.hour * 10000 + obj1.minute * 100 + obj1.second;
	int temp2 = obj2.hour * 10000 + obj2.minute * 100 + obj2.second;
	temp1 = abs(temp1 - temp2);
	temp2 = temp1 % 100;
	temp1 = temp1 / 100;
	cout << "\ndifference: ";
	cout << temp1 % 100 << ":" << temp1 / 100 << ":" << temp2 << endl;*/
	int temp1, temp2, temp3;
	int z = Time::Comparison(obj1, obj2);
	if (z == 1) {
		temp1 = obj1.second - obj2.second;
		if (temp1 < 0) {
			temp1 += 60;
			obj1.minute--;
		}
		temp2 = obj1.minute - obj2.minute;
		if (temp2 < 0) {
			temp2 += 60;
			obj1.hour--;
		}
		temp3 = obj1.hour - obj2.hour;
	}
	else if (z == 2) {
		temp1 = obj2.second - obj1.second;
		if (temp1 < 0) {
			temp1 = +60;
			obj2.minute--;
		}
		temp2 = obj2.minute - obj1.minute;
		if (temp2 < 0) {
			temp2 = +60;
			obj2.hour--;
		}
		temp3 = obj2.hour - obj1.hour;
	}
	else {
		temp1 = temp2 = temp3 = 00;
	}
	cout << "difference: " << temp3 << ":" << temp2 << ":" << temp1 << endl;
}

int Time::Comparison(Time obj1, Time obj2) {
	if (obj1.hour > obj2.hour) {
		cout << "time1 is bigger\n";
		return 1;
	}
	else if (obj2.hour > obj1.hour) {
		cout << "time2 is bigger\n";
		return 2;
	}
	else {
		if (obj1.minute > obj2.minute) {
			cout << "time1 is bigger\n";
			return 1;
		}
		else if (obj2.minute > obj1.minute) {
			cout << "time2 is bigger\n";
			return 2;
		}
		else {
			if (obj1.second > obj2.second) {
				cout << "time1 is bigger\n";
				return 1;
			}
			else if (obj2.second > obj1.second) {
				cout << "time2 is bigger\n";
				return 2;
			}
			else {
				cout << "time1 equals time2\n";
				return 0;
			}
		}
	}
}

int Time::GetDegree() {
	if (this->hour > 12)
		hour -= 12;
	int hour_degree = this->hour * 30;
	int minute_degree = this->minute * 6;
	return abs(hour_degree - minute_degree);
}