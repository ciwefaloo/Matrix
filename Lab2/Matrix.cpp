#include "Matrix.h"
#include<iostream>

using namespace std;


Matrix::Matrix(int p_n, int p_m, int p_mas[max][max]) {
	n = p_n;
	m = p_m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = p_mas[i][j];
		}
	}
}

void Matrix::c_out() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

