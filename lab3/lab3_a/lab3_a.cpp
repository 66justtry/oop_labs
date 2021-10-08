#include <iostream>
#include <string>

using namespace std;

class Sobaka {
protected:
	int weight;
	int age;
public:
	Sobaka() {
		cout << "Constructor of class Sobaka\n";
	}
	~Sobaka() {
		cout << "Destructor of class Sobaka\n";
	}
	void Info() {
		cout << "weight: " << weight << endl << "age: " << age << endl;
	}
	void SetWeight(int x) {
		weight = x;
	}
	void SetAge(int x) {
		age = x;
	}
	void Golos() {
		if (weight < 10)
			cout << "gaw\n";
		else
			cout << "GAW\n";
	}
};

class Spaniel :public Sobaka {
protected:
	string color;
public:
	Spaniel() {
		cout << "Constructor of class Spaniel\n";
	}
	~Spaniel() {
		cout << "Destructor of class Spaniel\n";
	}
	void SetColor(string x) {
		color = x;
	}
	void ShowColor() {
		cout << "color: " << color << endl;
	}
};

int main() {
	Spaniel obj;
	obj.SetWeight(15);
	obj.SetAge(3);
	obj.SetColor("Brown");
	obj.Info();
	obj.ShowColor();
	obj.Golos();
	system("pause");
	return 0;
}