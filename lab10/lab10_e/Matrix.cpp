#include "lab10_e.h"
#include "/111/хпи/2 курс/cpp/functions/Header.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Matrix::CreateMatrix(int n, int m) {
	this->n = n;
	this->m = m;
	this->ptr = new int* [n];
	for (int i = 0; i < n; i++)
		ptr[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			*(*(ptr + j) + i) = rand() % 100;
	//this->ptr = MatrRandomInt(ptr, n, m);
}

void Matrix::ShowMatrix() {
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << setw(4) << *(*(ptr + j) + i);
		cout << endl;
	}
	system("pause");
}

int* Matrix::FindMin() {
	int min = ptr[0][0];
	int min_n = 0, min_m = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (ptr[i][j] < min) {
				min = ptr[i][j];
				min_n = i;
				min_m = j;
			}
		}
	int* arr = new int[2];
	arr[0] = min_n;
	arr[1] = min_m;
	return arr;
}

int Matrix::GetNumber(int a, int b) {
	if ((a < n) && (b < m))
		return this->ptr[a][b];
	else
		return 0;
}

void Matrix::ChangeNumber(int a, int b, int num) {
	if ((a < n) && (b < m))
		this->ptr[a][b] = num;
}

void Matrix::SubMatrix(int posx, int posy, int a, int b) {
	system("cls");
	if ((posx + a <= n) && (posy + b <= m)) {
		for (int i = posx; i < posx + a; i++) {
			for (int j = posy; j < posy + b; j++)
				cout << setw(3) << ptr[j][i];
			cout << endl;
		}
	}
	else
		cout << "Error\n\n";
	system("pause");
}