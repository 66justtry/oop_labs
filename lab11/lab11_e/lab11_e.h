#pragma once

class Time {
private:
	int hour;
	int minute;
	int second;
public:
	Time() :hour(00), minute(00), second(00) {}
	int GetHour();
	int GetMinute();
	int GetSecond();
	void SetHour(int);
	void SetMinute(int);
	void SetSecond(int);
	void Show();
	static void Difference(Time, Time);
	static int Comparison(Time, Time);
	int GetDegree();
};

void menu();

void SetData(Time&);