#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileOut {
private:
	string str;
public:
	FileOut(string x) {
		str = x;
	}
	void show(ofstream& out) {
		out << *this;
	}
	friend ostream& operator<< (ostream& out, const FileOut& obj) {
		for (int i = 0; i < obj.str.length(); i++) {
			if ((isupper(obj.str[i])) || (isdigit(obj.str[i])))
				continue;
			out << obj.str[i];
		}
		return out;
	}
};

int main() {
	string s;
	cout << "Your line: ";
	cin >> s;
	FileOut* obj = new FileOut(s);
	try {
		ofstream out("out.txt");
		if (!out.is_open())
			throw " ";
		obj->show(out);
	}
	catch (string) {
		cout << "Error! File is not opened!\n";
	}
	delete obj;
	system("pause");
	return 0;
}