#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Numbers {
	int x;
	int y;
	int sum;
public:
	Numbers() {
		x = rand() % 5;
		y = rand() % 5;
		sum = x + y;
	}
	Numbers(int a, int b) {
		x = a;
		y = b;
		sum = a + b;
	}
	int GetSum() {
		return sum;
	}
	bool operator=(const Numbers& obj) {
		if (sum == obj.sum)
			return true;
		else
			return false;
	}
	bool operator>(const Numbers& obj) {
		if (sum > obj.sum)
			return true;
		else
			return false;
	}
};

int main() {
	srand(time(NULL));
	vector <Numbers> v1(3);
	vector <Numbers> v2(3);
	for (int i = 0; i < 3; i++) {
		int q;
		q = v1[i].GetSum();
		cout << "sum1 = " << q;
		q = v2[i].GetSum();
		cout << " sum2 = " << q << endl;
		if (v1[i] = v2[i])
			cout << "sum1 == sum2\n\n";
		else if (v1[i] > v2[i])
			cout << "sum1 > sum2\n\n";
		else
			cout << "sum1 < sum2\n\n";
	}
	system("pause");
	return 0;
}