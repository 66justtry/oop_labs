#include "lab11_d.h"
#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	Numbers obj1;
	obj1.Show();
	cout << "min: " << obj1.GetMin() << endl;
	cout << "max: " << obj1.GetMax() << endl;
	system("pause");
	Numbers obj2(10, 0, 15);
	obj2.Show();
	cout << "min: " << obj2.GetMin() << endl;
	cout << "max: " << obj2.GetMax() << endl;
	system("pause");
	Numbers obj3(obj2, 5);
	obj3.Show();
	cout << "min: " << obj3.GetMin() << endl;
	cout << "max: " << obj3.GetMax() << endl;
	system("pause");
	Numbers::Union(obj1, obj2);
	cout << "\n\n";
	system("pause");
	Numbers::Crossing(obj1, obj2);
	cout << "\n\n";
	system("pause");
	Numbers::Difference(obj1, obj2);
	cout << "\n\n";
	system("pause");
	Numbers::DisSum(obj1, obj2);
	cout << "\n\n";
	system("pause");
	return 0;
}
