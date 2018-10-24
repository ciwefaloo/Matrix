#pragma once

const int max = 105;

class Matrix
{
private:
	int n, m;
	int a[max][max];
public:
	Matrix(int p_n, int p_m,int p_mas[max][max]);
	void c_out();

	Matrix operator= (Matrix &temp);
	bool operator== (Matrix &temp);
};

