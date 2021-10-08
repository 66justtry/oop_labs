#include <iostream>
#include <string>

using namespace std;

class Book {
protected:
	string name;
	string author;
	int num_pages;
public:
	Book(string a, string b, int c) : name(a), author(b), num_pages(c) {}
	void ShowBook() {
		cout << "name: " << name << endl;
		cout << "author: " << author << endl;
		cout << "number of pages: " << num_pages << endl;
	}
};

class Library : public Book {
protected:
	int num;
	bool presence;
public:

};