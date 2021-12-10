#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>

using namespace std;

class Comp {
private:
	double num1;
	double num2;
public:
	void Set(double x, double y) {
		num1 = x;
		num2 = y;
	}
	void Show() {
		cout << fixed << setprecision(2) << num1 << " + " << num2 << "*i\n";
	}
};

int main() {
	srand(time(NULL));
	double* arr = new double[10];
	int x;
	double y;
	for (int i = 0; i < 10; i++) {
		x = rand() % 20;
		y = rand() % 100;
		y = y / 100;
		arr[i] = x + y;
		cout << arr[i] << endl;
	}
	cout << "\n\n";
	fstream in("in.txt", ios::binary | ios::out);
	for (int i = 0; i < 10; i++) {
		double q = arr[i];
		in.write((char*)&arr[i], sizeof(double));
	}
	in.close();
	Comp* numbers = new Comp[5];
	try {
		in.open("in.txt", ios::binary | ios::in);
		if (!in.is_open())
			throw 1;
		double temp1, temp2;
		for (int i = 0; i < 5; i += 2) {
			in.read((char*)&temp1, sizeof(double));
			in.read((char*)&temp2, sizeof(double));
			//cout << temp1 << " " << temp2 << endl;
			numbers[i].Set(temp1, temp2);
		}
		in.close();
	}
	catch (int) {
		cout << "Error!\n";
		return 1;
	}
	for (int i = 0; i < 5; i++)
		numbers[i].Set(arr[2 * i], arr[2 * i + 1]);
	for (int i = 0; i < 5; i++)
		numbers[i].Show();
	ofstream out("out.txt", ios::binary);
	out.write((char*)numbers, sizeof(numbers));
	out.close();
	delete[] arr;
	delete[] numbers;
	system("pause");
}