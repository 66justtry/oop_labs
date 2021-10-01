#include "lab11_d.h"
#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

void menu(Numbers* numbers) {
	system("cls");
	int ch;
	cout << "1 - Find min/max\n";
	cout << "2 - Union\n";
	cout << "3 - Crossing\n";
	cout << "4 - Difference\n";
	cout << "5 - Disjunctive sum\n";
	cout << "6 - Exit\n";
	cin >> ch;
	if (ch == 1) {
		int x;
		system("cls");
		cout << "Enter the number of object: ";
		cin >> x;
		x--;
		numbers[x].Show();
		cout << "min: " << numbers[x].GetMin() << endl;
		cout << "max: " << numbers[x].GetMax() << endl;
		system("pause");
	}
	else if (ch == 2) {
		int x, y;
		system("cls");
		cout << "Enter 2 numbers of objects:\n";
		cout << "n1: ";
		cin >> x;
		x--;
		cout << "n2: ";
		cin >> y;
		y--;
		system("cls");
		numbers[x].Show();
		numbers[y].Show();
		Numbers::Union(numbers[x], numbers[y]);
		system("pause");
	}
	else if (ch == 3) {
		int x, y;
		system("cls");
		cout << "Enter 2 numbers of objects:\n";
		cout << "n1: ";
		cin >> x;
		x--;
		cout << "n2: ";
		cin >> y;
		y--;
		system("cls");
		numbers[x].Show();
		numbers[y].Show();
		Numbers::Crossing(numbers[x], numbers[y]);
		system("pause");
	}
	else if (ch == 4) {
		int x, y;
		system("cls");
		cout << "Enter 2 numbers of objects:\n";
		cout << "n1: ";
		cin >> x;
		x--;
		cout << "n2: ";
		cin >> y;
		y--;
		system("cls");
		numbers[x].Show();
		numbers[y].Show();
		Numbers::Difference(numbers[x], numbers[y]);
		system("pause");
	}
	else if (ch == 5) {
		int x, y;
		system("cls");
		cout << "Enter 2 numbers of objects:\n";
		cout << "n1: ";
		cin >> x;
		x--;
		cout << "n2: ";
		cin >> y;
		y--;
		system("cls");
		numbers[x].Show();
		numbers[y].Show();
		Numbers::DisSum(numbers[x], numbers[y]);
		system("pause");
	}
	else if (ch == 6)
		exit(0);
	menu(numbers);
}

int main() {
	srand(time(NULL));
	int n, min, max;
	Numbers* numbers = new Numbers[3];
	cout << "Well, now you must create 3 objects:\n";
	cout << "1 - default object\n";
	cout << "2 - object with your parameters\n";
	cout << "3 - object-copy of second object, but with changes\n";
	cout << "\nSo, please enter parameters for second object:\n";
	numbers[0];
	cout << "N: ";
	cin >> n;
	cout << "Min: ";
	cin >> min;
	cout << "Max: ";
	cin >> max;
	numbers[1] = { n, min, max };
	cout << "Okay, now enter the max number you want to copy to the third object:\n";
	cout << "N: ";
	cin >> n;
	numbers[2] = { numbers[1], n };
	cout << "\nThat's all!\n";
	Show(numbers);
	system("pause");
	menu(numbers);


	delete[] numbers;
	system("pause");
	return 0;
}

void Show(Numbers* numbers) {
	for (int i = 0; i < 3; i++) {
		numbers[i].Show();
	}
}
