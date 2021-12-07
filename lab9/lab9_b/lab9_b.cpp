#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

class Name {
	string name;
public:
	Name() {
		name = "";
	}
	Name(string x) {
		name = x;
	}
	void Get() {
		cout << name;
	}
	void Set(string x) {
		name = x;
	}
	char operator[] (int i) {
		char q;
		if (name.size() < i)
			q = '0';
		else
			q = name[i];
		return q;
	}
	friend ostream& operator<< (ostream& out, const Name& obj);
	friend bool operator> (const Name& obj1, const Name& obj2);
	friend bool operator< (const Name& obj1, const Name& obj2);
	friend bool operator== (const Name& obj1, const Name& obj2);
	friend bool operator== (const Name& obj1, const string& obj2);
};

class Number {
	int number;
public:
	Number() {
		number = 0;
	}
	Number(int x) {
		number = x;
	}
	void Get() {
		cout << number;
	}
	void Set(int x) {
		number = x;
	}
	friend ostream& operator<< (ostream& out, const Number& obj);
};

void Find(map<Name, Number> mp, char q) {
	map <Name, Number> ::iterator it;
	it = mp.begin();
	for (int i = 0; i < mp.size(); i++) {
		Name temp = it->first;
		if (temp[0] == q)
			cout << it->first << " " << it->second << endl;
		it++;
	}
}

void Delete(map<Name, Number>& mp, char q) {
	map <Name, Number> ::iterator it;
	it = mp.begin();
	int z = mp.size();
	for (int i = 0; i < z; i++) {
		Name temp = it->first;
		if (temp[0] == q) {
			mp.erase(it->first);
			it = mp.begin();
			advance(it, i);
			i--;
			z--;
		}
		else
			it++;
	}
	it = mp.begin();
	/*for (int i = 0; i < mp.size(); i++) {
		cout << it->first << " " << it->second << endl;
		it++;
	}*/
}

int main() {
	map <Name, Number> mp;
	Name* names = new Name[5];
	Number* numbers = new Number[5];
	string x;
	int y;
	map <Name, Number> ::iterator it;
	ifstream in("text.txt");
	for (int i = 0; i < 5; i++) {
		in >> x >> y;
		names[i].Set(x);
		numbers[i].Set(y);
	}
	in.close();
	for (int i = 0; i < 5; i++) {
		mp.insert({ names[i], numbers[i] });
	}
	for (const auto& p : mp) {
		cout << p.first << " " << p.second << endl;
	}
	cout << "\n\n";
	Name q("Slava");
	try {
		cout << "Your request: " << q << endl;
		it = mp.find(q);
		if (it == mp.end())
			throw 1;
		cout << "Number: " << it->second << endl;
	}
	catch (int) {
		cout << "You don't have a number of this person!\n";
	}
	cout << "\n\n";
	cout << "Your request: 'S'\n";
	Find(mp, 'S');
	cout << "\n\n";
	cout << "Deleting pairs with 'S'...\n";
	Delete(mp, 'S');
	for (const auto& p : mp) {
		cout << p.first << " " << p.second << endl;
	}
	delete[] names;
	delete[] numbers;
	system("pause");
	return 0;
}

ostream& operator<< (ostream& out, const Name& obj) {
	out << obj.name;
	return out;
}

ostream& operator<< (ostream& out, const Number& obj) {
	out << obj.number;
	return out;
}

bool operator> (const Name& obj1, const Name& obj2) {
	if (obj1.name > obj2.name)
		return true;
	else
		return false;
}

bool operator< (const Name& obj1, const Name& obj2) {
	if (obj1.name < obj2.name)
		return true;
	else
		return false;
}

bool operator== (const Name& obj1, const Name& obj2) {
	if (obj1.name == obj2.name)
		return true;
	else
		return false;
}

bool operator== (const Name& obj1, const string& obj2) {
	if (obj1.name == obj2)
		return true;
	else
		return false;
}