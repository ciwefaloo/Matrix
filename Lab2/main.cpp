#include<iostream>
#include "Matrix.h"

using namespace std;

const int max_size = 105;

int main() {

	int n,m;
	cin >> n >> m;
	Matrix matrix = Matrix(n, m);
	matrix >> matrix;
	matrix.gauss_method();
	//matrix.c_out();
	system("pause");
	return 0;

}