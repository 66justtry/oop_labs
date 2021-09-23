#include "lab11_d.h"
#include <time.h>
#include <iostream>

using namespace std;

Numbers::Numbers() {
	this->n = 10;
	this->min = -20;
	this->max = 20;
	this->arr = new int[n];
	this->Generate();
}

Numbers::Numbers(int n, int min, int max) {
	this->n = n;
	this->min = min;
	this->max = max;
	this->arr = new int[n];
	this->Generate();
}

Numbers::Numbers(Numbers& numb, int a) {
	int x = 0;
	for (int i = 0; i < numb.n; i++)
		if (numb.arr[i] <= a)
			x++;
	this->n = x;
	this->arr = new int[x];
	x = 0;
	for (int i = 0; i < numb.n; i++)
		if (numb.arr[i] <= a) {
			this->arr[x] = numb.arr[i];
			x++;
		}
	this->min = this->GetMin();
	this->max = this->GetMax();
}

int Numbers::GetMin() {
	int min = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] < min)
			min = arr[i];
	return min;
}

int Numbers::GetMax() {
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void Numbers::Generate() {
	int len = abs(max - min) + 1;
	if (len < n)
		return;
	if ((len / n) >= 3) {
		for (int i = 0; i < n; i++) {
			start:
			arr[i] = min + rand() % (abs(max - min) + 1);
			for (int j = 0; j < i; j++) {
				if (arr[j] == arr[i])
					goto start;
			}
		}
	}
	else {
		int x;
		int* z = new int[len];
		for (int i = 0; i < len; i++)
			z[i] = i;
		for (int i = 0; i < n; i++) {
			x = min + rand() % len;
			arr[i] = z[x];
			//z[len - 1] = z[x];
			//z[x] = len;
			swap(z[x], z[len - 1]);
			len--;
		}
		delete[] z;
	}
}

void Numbers::Show() {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

void Numbers::Union(Numbers obj1, Numbers obj2) {
	bool q;
	cout << "union: ";
	for (int i = 0; i < obj1.n; i++)
		cout << obj1.arr[i] << " ";
	for (int i = 0; i < obj2.n; i++) {
		q = false;
		for (int j = 0; j < obj1.n; j++) {
			if (obj2.arr[i] == obj1.arr[j]) {
				q = true; //если найдено совпадение
				break;
			}
		}
		if (q == false)
			cout << obj2.arr[i] << " ";
	}
	cout << endl;
}

void Numbers::Crossing(Numbers obj1, Numbers obj2) {
	cout << "crossing: ";
	for (int i = 0; i < obj1.n; i++) {
		for (int j = 0; j < obj2.n; j++)
			if (obj1.arr[i] == obj2.arr[j]) {
				cout << obj1.arr[i] << " ";
				break;
			}
	}
	cout << endl;
}

void Numbers::Difference(Numbers obj1, Numbers obj2) {
	bool q;
	cout << "difference: ";
	for (int i = 0; i < obj1.n; i++) {
		q = false;
		for (int j = 0; j < obj2.n; j++) {
			if (obj1.arr[i] == obj2.arr[j]) {
				q = true; //найдено совпадение, не печатаем
				break;
			}
		}
		if (q == false)
			cout << obj1.arr[i] << " ";
	}
	cout << endl;
}

void Numbers::DisSum(Numbers obj1, Numbers obj2) {
	bool q;
	cout << "disjunctive sum: ";
	for (int i = 0; i < obj1.n; i++) {
		q = false;
		for (int j = 0; j < obj2.n; j++)
			if (obj1.arr[i] == obj2.arr[j]) {
				q = true;
				break;
			}
		if (q == false)
			cout << obj1.arr[i] << " ";
	}
	for (int i = 0; i < obj2.n; i++) {
		q = false;
		for (int j = 0; j < obj1.n; j++)
			if (obj2.arr[i] == obj1.arr[j]) {
				q = true;
				break;
			}
		if (q == false)
			cout << obj2.arr[i] << " ";
	}
	cout << endl;
}