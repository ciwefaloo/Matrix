#include<iostream>

using namespace std;

class Matrix {
private:
	int n, m;
	double **arr = new double*[n];
	double esp = 0.00001;
public:
	Matrix(int p_n, int p_m);

	Matrix() = default;

	Matrix operator= (const Matrix &temp);

	bool operator== (Matrix &temp);

	Matrix operator+ (const Matrix &temp);

	Matrix operator- (const Matrix &temp);

	Matrix operator* (const Matrix &temp);

	Matrix copy();

	Matrix operator* (const double &temp);

	double* operator[](int x);

	friend istream& operator >>(istream& stream, Matrix &temp);

	friend ostream& operator <<(ostream& stream, Matrix &temp);

	void operator ~();

	void gauss_method(double *ans);

	bool symmetry();

	void jacobi(double *ans);

	double scalar(Matrix &obj, int row, double* u);

	double norma(Matrix obj, int row);

	double len(double* u);

	double* kachmazh();
};