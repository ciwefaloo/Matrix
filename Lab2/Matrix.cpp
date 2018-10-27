#include "Matrix.h"
#include<iostream>

using namespace std;


Matrix::Matrix(int p_n, int p_m) {
	n = p_n;
	m = p_m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = 0;
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
	for (int i = 0; i < temp.n; i++) {
		for (int j = 0; j < temp.m; j++) {
			a[i][j] = temp.a[i][j];
		}
	}
	return *this;
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

Matrix Matrix::operator+ (Matrix &temp) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] += + temp.a[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator- (Matrix &temp) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] -= temp.a[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator* (Matrix &temp) {
	Matrix x = Matrix(n,m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				x.a[i][j] = x.a[i][j] + a[i][k] * temp.a[k][j];
			}
		}
	}
	return x;
}

Matrix Matrix::operator* (double &temp) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] *= temp;
		}
	}
	return *this;
}


void Matrix::operator >> (Matrix &temp) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
}

void Matrix::operator << (Matrix &temp) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::operator ~() {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < m; j++) {
			swap(a[i][j],a[j][i]);
		}
	}
}