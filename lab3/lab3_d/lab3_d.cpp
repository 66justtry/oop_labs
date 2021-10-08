#include <iostream>

using namespace std;

class Figure {
protected:
	int x;
	int y;
public:
	Figure(int a, int b) : x(a), y(b) {}
	virtual void Show() = 0;
	void Set(int a, int b) {
		x = a;
		y = b;
	}
};

class A1 : public Figure {
public:
	A1(int a, int b) : Figure(a, b) {}
	void Show() {
		cout << "S = " << x * y / 2 << endl;
	}
};

class A2 : public Figure {
public:
	A2(int a, int b) : Figure(a, b) {}
	void Show() {
		cout << "S = " << x * y << endl;
	}
};

class A3 : public Figure {
public:
	A3(int a, int b = 1) : Figure(a, b) {}
	void Show() {
		cout << "S = " << x * x * 3.14 << endl;
	}
};

int main() {
	A1 obj1(4, 5);
	obj1.Show();
	A2 obj2(3, 4);
	obj2.Show();
	A3 obj3(1);
	obj3.Show();
	system("pause");
	return 0;
}