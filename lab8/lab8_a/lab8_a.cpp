#include <iostream>
using namespace std;

template <class T>
class Number {
	T num;
public:
	Number() {
		num = 0;
	}
	Number(T x) {
		num = x;
	}
	void Show() {
		cout << "number: " << num << endl;
	}
	friend Number<T> operator/ (const Number<T>& obj1, const Number<T>& obj2) {
		Number<T> temp;
		temp.num = obj1.num / obj2.num;
		return temp;
	}
	Number& operator= (const Number&);
};

int main() {
	Number <int> obj1(12);
	Number <int> obj2(3);
	obj1.Show();
	obj2.Show();
	Number <int> obj3 = (obj1 / obj2);
	obj3.Show();
	cout << endl;
	Number <double> obj4(10.5);
	Number <double> obj5(2.5);
	obj4.Show();
	obj5.Show();
	Number <double> obj6 = obj4 / obj5;
	obj6.Show();
	system("pause");
	return 0;
}

template<class T>
Number<T>& Number<T>::operator= (const Number& obj) {
	Number<T> temp;
	temp.num = obj.num;
	return temp;
}
