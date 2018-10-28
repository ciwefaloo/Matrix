#pragma once

const int max = 105;

class Matrix
{
private:
	int n, m;
	double a[max][max];
public:
	Matrix(int p_n, int p_m);
	void c_out();
	Matrix operator= (Matrix &temp);
	bool operator== (Matrix &temp);
	Matrix operator+ (Matrix &temp);
	Matrix operator- (Matrix &temp);
	Matrix operator* (Matrix &temp);
	Matrix operator* (double  &temp);
	void operator >>(Matrix &temp);
	void operator <<(Matrix &temp);
	void operator ~();
	void gauss_method();
};

