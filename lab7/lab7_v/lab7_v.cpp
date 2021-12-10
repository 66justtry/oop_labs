#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	int* arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	ofstream out("text.txt");
	for (int i = 0; i < 10; i++)
		out << arr[i] << " ";
	out.close();
	int num;
	ifstream in("text.txt");
	in.seekg(3 * sizeof(int), ios::beg);
	in >> num;
	num = arr[4];
	in.close();
	try {
		if (num % 2 == 0) {
			out.open("text.txt");
			if (!out.is_open())
				throw 1;
			for (int i = 0; i < 4; i++)
				out << 77 << " ";
			for (int i = 4; i < 10; i++)
				out << arr[i] << " ";
			out.close();
		}
		else {
			out.open("text.txt");
			if (!out.is_open())
				throw 1;
			for (int i = 0; i < 5; i++)
				out << arr[i] << " ";
			for (int i = 0; i < 5; i++)
				out << 88 << " ";
			out.close();
		}
	}
	catch (int) {
		cout << "Error!\n";
		return 1;
	}
	in.open("text.txt");
	for (int i = 0; i < 10; i++)
		in >> arr[i];
	in.close();
	cout << "\n\n";
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << "\n\n";
	delete[] arr;
	system("pause");
	return 0;
}