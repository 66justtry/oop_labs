#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Book {
public:
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
public:
	int num;
	bool presence;
public:
	Library(string a, string b, int c, int d, bool e) : Book(a, b, c), num(d), presence(e) {}
	void ShowLibrary() {
		this->ShowBook();
		cout << "number of library: " << num << endl;
		cout << "presence: " << boolalpha << presence << endl;
		cout << "\n";
	}
};

void menu(Library* books) {
	system("cls");
	string x;
	for (int i = 0; i < 3; i++)
		books[i].ShowLibrary();
	cout << "------------------------------\n\n";
	cout << "Enter the name of book you are looking for:\n";
	getline(cin, x);
	for (int i = 0; i < 3; i++) {
		if (x == books[i].name) {
			books[i].ShowLibrary();
			books[i].presence = false;
		}
	}
	system("pause");
	menu(books);
}

int main() {
	Library* books = new Library[3]{
		{"Star Wars", "J.Laker", 500, 102344, true},
		{"Witcher", "I.Zhavets", 218, 2237684, true},
		{"LoTR", "J.Tolkien", 467, 125630, false}
	};
	menu(books);


	delete[] books;
	system("pause");
}