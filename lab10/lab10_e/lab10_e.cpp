#include "lab10_e.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

Matrix matr;

void menu() {
	system("cls");
	int ch;
	cout << "1 - Show matrix\n";
	cout << "2 - Find position of minimal number\n";
	cout << "3 - Find a number by its position\n";
	cout << "4 - Change a number by its position\n";
	cout << "5 - Get a submatrix\n";
	cout << "6 - Exit\n";
	cin >> ch;
	if (ch == 1) {
		matr.ShowMatrix();
	}
	else if (ch == 2) {
		system("cls");
		int* arr = matr.FindMin();
		cout << "Position of minimal element: " << arr[0] << " " << arr[1] << endl;
		delete[] arr;
		system("pause");
	}
	else if (ch == 3) {
		int n, m;
		system("cls");
		cout << "N: ";
		cin >> n;
		cout << "M: ";
		cin >> m;
		int num = matr.GetNumber(n, m);
		cout << "Your number: " << num << endl;
		system("pause");
	}
	else if (ch == 4) {
		int n, m;
		system("cls");
		cout << "N: ";
		cin >> n;
		cout << "M: ";
		cin >> m;
		int num;
		cout << "New number: ";
		cin >> num;
		matr.ChangeNumber(n, m, num);
		cout << "\nThe number was changed\n";
		system("pause");
	}
	else if (ch == 5) {
		system("cls");
		int posx, posy;
		int a, b;
		cout << "Position of first element:\n";
		cout << "N: ";
		cin >> posx;
		cout << "M: ";
		cin >> posy;
		cout << "The size of submatrix:\n";
		cout << "N: ";
		cin >> a;
		cout << "M: ";
		cin >> b;
		matr.SubMatrix(posx, posy, a, b);
	}
	else if (ch == 6) {
		exit(0);
	}
	menu();
}



int main() {
	srand(time(NULL));
	int n, m;
	cout << "N: ";
	cin >> n;
	cout << "M: ";
	cin >> m;
	matr.CreateMatrix(n, m);
	menu();
	return 0;
}