#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.graphics.h>
using namespace std;

template <class T>
class Array {
	T* arr;
	int size;
	int ind;
public:
	Array();
	int GetSize();
	int GetIndex();
	void SetIndex(int);
	void SetData(int, T&);
	T GetSum();
	double GetMiddle();
	void Show();
	void ShowAll();
	T operator[] (int);
	~Array();
};

template <class T>
void menu(Array<T>&);



template<class T>
Array<T>::Array() {
	arr = new T[20];
	size = 20;
	for (int i = 0; i < size; i++)
		arr[i] = 0;
	ind = 0;
}

template<class T>
int Array<T>::GetSize() {
	return size;
}

template<class T>
void Array<T>::SetData(int n, T& x) {
	arr[n] = x;
}

template<class T>
T Array<T>::GetSum() {
	T temp = 0;
	for (int i = 0; i < ind; i++)
		temp += arr[i];
	return temp;
}

template <class T>
double Array<T>::GetMiddle() {
	double temp = this->GetSum();
	return temp / ind;
}

template<class T>
void Array<T>::Show() {
	cout << endl;
	for (int i = 0; i < ind; i++)
		cout << arr[i] << " ";
	cout << endl;
}

template<class T>
void Array<T>::ShowAll() {
	if (ind == 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
		cout << "|";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (i == ind - 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
			cout << "|";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		}
		else
			cout << " ";
	}
	cout << endl;
}

template<class T>
T Array<T>::operator[](int) {
	T max = arr[0];
	for (int i = 1; i < ind; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

template<class T>
Array<T>::~Array() {
	delete[] arr;
}

template<class T>
int Array<T>::GetIndex() {
	return ind;
}

template<class T>
void Array<T>::SetIndex(int x) {
	ind = x;
}
