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

Matrix Matrix::operator= (Matrix &temp) {
	n = temp.n;
	m = temp.m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = temp.a[i][j];
		}
	}
	return temp;
}

bool Matrix::operator== (Matrix &temp) {
	if (n == temp.n && m == temp.m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != temp.a[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}

