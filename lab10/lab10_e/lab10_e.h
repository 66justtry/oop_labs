#pragma once

class Matrix {
private:
	int n;
	int m;
	int** ptr;
public:
	void CreateMatrix(int, int);
	void ShowMatrix();
	int* FindMin();
	int GetNumber(int, int);
	void ChangeNumber(int, int, int);
	void SubMatrix(int, int, int, int);
};

void menu();