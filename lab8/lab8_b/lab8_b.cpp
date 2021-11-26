#include "lab8_b.h"
#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	system("color F0");
	Array<int> obj;
	menu(obj);
	return 0;
}

template <class T>
void menu(Array<T>& obj) {
	int q = obj.GetIndex();
	system("cls");
	obj.ShowAll();
	cout << "Current index: " << q << "\n\n";
	cout << "1 - Create new array\n";
	cout << "2 - Change index\n";
	cout << "3 - Enter random numbers\n";
	cout << "4 - Get sum\n";
	cout << "5 - Get middle\n";
	cout << "6 - Print\n";
	cout << "7 - Get max\n";
	cout << "8 - Exit\n";
	cout << endl;
	int ch;
	cin >> ch;
	if (ch == 1) {
		int q = obj.GetSize();
		T z = 0;
		for (int i = 0; i < q; i++)
			obj.SetData(i, z);
		obj.SetIndex(0);
	}
	else if (ch == 2) {
		int q;
		int x = obj.GetSize();
		cout << "index: ";
		cin >> q;
		try {
			if ((q > x) || (q < 0))
				throw 0;
			obj.SetIndex(q);
		}
		catch (int) {
			cout << "Wrong number!\n";
		}
	}
	else if (ch == 3) {
		int index = obj.GetIndex();
		T q;
		for (int i = 0; i < index; i++) {
			q = rand() % 10;
			obj.SetData(i, q);
		}
	}
	else if (ch == 4) {
		int q = obj.GetSum();
		cout << "Sum: " << q << endl;
	}
	else if (ch == 5) {
		double q = obj.GetMiddle();
		cout << "Middle: " << q << endl;
	}
	else if (ch == 6) {
		obj.Show();
	}
	else if (ch == 7) {
		T q = obj[0];
		cout << "Max: " << q << endl;
	}
	else if (ch == 8) {
		return;
	}


	system("pause");
	menu(obj);
}