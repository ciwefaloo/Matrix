#include<iostream>
#include "Matrix.h"

using namespace std;

int main() {

	int n, m;
	cout << "size matrix: ";
	cin >> n >> m;
	Matrix matrix = Matrix(n, m);
	cin >> matrix;
	int type;
	cout << "select method:\n 1-gauss \n 2-jacobi\n 3-kachmazh\n";
	cin >> type;
	double *ans = new  double[n];
	for (int i = 0; i < n; i++) {
		ans[i] = 0;
	}

	bool flag = true;
	if (type == 1) {
		matrix.gauss_method(ans);
	}
	else if (type == 2) {
		if (!matrix.symmetry()) {
			cout << "matrix dont symmetry" << endl;
			flag = false;
		}
		else {
			matrix.jacobi(ans);

		}
	}
	else if (type == 3) {
		ans = matrix.kachmazh();
	}
	else {
		cout << "invalid type" << endl;
		flag = false;
	}
	if (flag) {
		for (int i = 0; i < n; i++) {
			cout << "x" << i + 1 << " = " << ans[i] << ";" << endl;
		}
	}
	system("pause");
	return 0;

}