#include <iostream>

using namespace std;

class B1 {
	int b1;
public:
	B1(int x) { b1 = x; }
};

class B2 {
	int b2;
public:
	B2(int x) { b2 = x; }
};

class D1 : virtual public B1 {
	int d1;
public:
	D1(int x, int y) : B1(y) { d1 = x; }
};

class D2 : private D1 {
	int d2;
public:
	D2(int x, int y, int z) : B1(y), D1(z, y) { d2 = x; }
};

class D3 : public D2, virtual private B2 {
	int d3;
public:
	D3(int x, int y, int z, int i, int j) : B1(y), B2(z), D2(i, y, j) { d3 = x; }
};