#include <iostream>
#include <string>
#include <fstream>

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
	Library(string a, string b, int c, int d, bool e) : Book(a, b, c), num(d), presence(e) {}
	void ShowLibrary() {
		cout << "number of library: " << num << endl;
		cout << "presence: " << presence << endl;
	}
};

int main() {
	Library* temp = new Library;
	Library* books = new Library[3];
	Library books[0] = ("Star Wars", "J.Laker", 500, 102344, true);
	Library books[1] = ("Witcher", "I.Zhavets", 218, 2237684, true);
	Library books[2] = ("LoTR", "J.Tolkien", 467, 125630, false);
}