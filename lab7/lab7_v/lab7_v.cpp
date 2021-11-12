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
	ofstream out("text.txt", ios::binary);
	for (int i = 0; i < 10; i++)
		out << arr[i];
	out.close();
	ifstream in("text.txt", ios::binary);
	in.seekg(3 * sizeof(int), ios::beg);
	int num;
	in >> num;
	in.close();
	if (num % 2 == 0) {
		out.open("text.txt", ios::binary);
		for (int i = 0; i < 4; i++)
			out.write((char*)(77), sizeof(int));
		out.close();
	}
	else {
		out.open("text.txt", ios::binary);
		out.seekp(4 * sizeof(int), ios::beg);
		for (int i = 0; i < 5; i++)
			out.write((char*)(88), sizeof(int));
		out.close();
	}
	in.open("text.txt", ios::binary);
	for (int i = 0; i < 10; i++)
		in >> arr[i];
	in.close();
	cout << "\n\n";
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	delete[] arr;
	system("pause");
	return 0;
}