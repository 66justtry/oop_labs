#include <iostream>
#include <fstream>
#include <iomanip>
#include "lab7_g.h"

using namespace std;

ostream& operator<< (ostream& out, const Project& obj) {
	out << setw(5) << obj.year << setw(13) << obj.name << setw(13) << obj.diameter << setw(20) << obj.frequency << endl;
	return out;
}

void menu(DB* database) {
	system("cls");
	database->Show();
	cout << "\n\n";
	cout << "1 - Create default database\n";
	cout << "2 - Change a line\n";
	cout << "3 - Read a database from file\n";
	cout << "4 - Read a line from file\n";
	cout << "5 - Save the database to file\n";
	cout << "6 - Save the line to file\n";
	cout << "7 - Exit\n";
	int ch;
	cin >> ch;
	if (ch == 1) {
		database->ReadFromFileAll("default.txt");
	}
	else if (ch == 2) {
		cout << "\nline: ";
		int q;
		cin >> q;
		q--;
		int x1, x3, x4;
		string x2;
		cout << "year: ";
		cin >> x1;
		cout << "name: ";
		cin >> x2;
		cout << "diameter: ";
		cin >> x3;
		cout << "frequency: ";
		cin >> x4;
		database->Setline(q, x1, x2, x3, x4);
	}
	else if (ch == 3) {
		database->ReadFromFileAll("text.txt");
	}
	else if (ch == 4) {
		cout << "\nline: ";
		int q;
		cin >> q;
		q--;
		Project temp = database->ReadFromFile("text.txt", q);
		database->Add(temp);
	}
	else if (ch == 5) {
		database->SaveToFileAll("text.txt");
	}
	else if (ch == 6) {
		cout << "\nline: ";
		int q;
		cin >> q;
		q--;
		Project temp = database->Getline(q);
		database->SaveToFile("text.txt", temp);
	}
	else if (ch == 7)
		return;
	system("pause");
	menu(database);
}

int main() {
	DB* database = new DB;
	menu(database);
	delete database;
	return 0;
}