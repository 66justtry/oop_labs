//#include "lab8_b.h"
//#include <iostream>
//using namespace std;
//
//template<class T>
//Array<T>::Array() {
//	arr = new T[10];
//	size = 10;
//	ind = 0;
//}
//
//template<class T>
//void Array<T>::SetData(int n, T& x) {
//	arr[n] = x;
//}
//
//template<class T>
//T Array<T>::GetSum() {
//	T temp = 0;
//	for (int i = 0; i < ind; i++)
//		temp += arr[i];
//	return temp;
//}
//
//template <class T>
//T Array<T>::GetMiddle() {
//	T temp = this->GetSum();
//	temp / ind;
//	return temp;
//}
//
//template<class T>
//void Array<T>::Show() {
//	for (int i = 0; i < ind; i++)
//		cout << arr[i] << endl;
//}
//
//template<class T>
//void Array<T>::ShowAll() {
//	for (int i = 0; i < size; i++)
//		cout << arr[i] << " ";
//	cout << endl;
//}
//
//template<class T>
//T Array<T>::operator[](const Array& obj) {
//	T max = obj.arr[0];
//	for (int i = 1; i < obj.ind; i++)
//		if (obj.arr[i] > max)
//			max = obj.arr[i];
//	return max;
//}
//
//template<class T>
//Array<T>::~Array() {
//	delete[] arr;
//}
//
//template<class T>
//int Array<T>::GetIndex() {
//	return ind;
//}
