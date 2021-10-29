#include <iostream>
#include <string>
#include <fstream>
#include "lab3_d.h"

using namespace std;


int main() {
	Vuz* shtat = new Vuz;
	shtat->prepods = new Prepod[2];
	shtat->prepods_n = 2;
	shtat->zav_kafs = new Zav_kaf[1];
	shtat->zav_kafs_n = 1;
	shtat->students = new Student[3];
	shtat->students_n = 3;
	ifstream in;
	in.open("info.txt");
	for (int i = 0; i < shtat->prepods_n; i++)
		in >> shtat->prepods[i].name >> shtat->prepods[i].age >> shtat->prepods[i].subject >> shtat->prepods[i].degree;
	for (int i = 0; i < shtat->zav_kafs_n; i++)
		in >> shtat->zav_kafs[i].name >> shtat->zav_kafs[i].age >> shtat->zav_kafs[i].position;
	for (int i = 0; i < shtat->students_n; i++) {
		in >> shtat->students[i].name >> shtat->students[i].age;
		shtat->students[i].marks = new int[5];
		for (int j = 0; j < 5; j++) {
			in >> shtat->students[i].marks[j];
		}
	}
	in.close();
	cout << "All the persons:\n\n";
	shtat->print_all();
	cout << "----------------------------------------------\n";
	shtat->print_request();
	cout << "\n\n";



	{
		for (int i = 0; i < shtat->students_n; i++)
			delete[] shtat->students[i].marks;
		delete[] shtat->prepods;
		delete[] shtat->zav_kafs;
		delete[] shtat->students;
		delete shtat;
	}
	system("pause");
	return 0;
}