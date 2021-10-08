#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

class Number {
protected:
	int x;
public:
	void SetNumber(int q) {
		x = q;
	}
	void Show() {
		cout << setw(3) << x;
	}
};

class Number1 : public Number {
protected:
	int y; //ostatok pri delenii na 7
public:
	void SetY() {
		y = x % 7;
	}
	int GetY() {
		return y;
	}
	void ShowY() {
		cout << setw(3) << y;
	}
};

class Number2 : public Number1 {
protected:
	int z; //ostatok pri delenii na 5
public:
	void SetZ() {
		z = x % 5;
	}
	int GetZ() {
		return z;
	}
	void ShowZ() {
		cout << setw(3) << z;
	}
};

int main() {
	srand(time(NULL));
	Number2* arr = new Number2[10];
	cout << "  N   %7  %5  \n";
	for (int i = 0; i < 10; i++) {
		int q = rand() % 50;
		arr[i].SetNumber(q);
		arr[i].SetY();
		arr[i].SetZ();
		arr[i].Show();
		cout << " ";
		arr[i].ShowY();
		cout << " ";
		arr[i].ShowZ();
		cout << endl;
	}
	cout << "\n\n";
	cout << "The numbers by condition: ";
	for (int i = 0; i < 10; i++)
		if ((arr[i].GetY() == 3) && (arr[i].GetZ() == 2)) {
			arr[i].Show();
			cout << " ";
		}
	cout << "\n\nP. S. For numbers 0-50 the only one right number is 17\n\n";
	system("pause");
	delete[] arr;
	return 0;
}