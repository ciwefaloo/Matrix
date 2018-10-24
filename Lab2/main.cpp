#include<iostream>
#include "Matrix.h"

using namespace std;

const int max_size = 105;

int main() {

	int n,m;
	cin >> n >> m;

	int mas[max_size][max_size];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mas[i][j];
		}
	}

	Matrix matrix = Matrix(n, m, mas);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mas[i][j];
		}
	}
	Matrix matrix2 = Matrix(n, m, mas);
	//matrix = matrix2;
	if (matrix == matrix2) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	matrix.c_out();
	system("pause");
	return 0;
}