#include "MAtrix.h"



Matrix::Matrix(int p_n, int p_m) {
	n = p_n;
	m = p_m;
	for (int i = 0; i < n; i++) {
		arr[i] = new double[m];
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
		}
	}
}

Matrix Matrix::operator= (const Matrix &temp) {
	Matrix obj = copy();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			obj.arr[i][j] = temp.arr[i][j];
		}
	}
	return obj;
}

bool Matrix::operator== (Matrix &temp) {
	if (n != temp.n || m != temp.m) {
		return false;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != temp.arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}
Matrix Matrix::operator+ (const Matrix &temp) {
	Matrix obj = copy();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			obj.arr[i][j] += temp.arr[i][j];
		}
	}
	return obj;
}
Matrix Matrix::operator- (const Matrix &temp) {
	Matrix obj = copy();
	for (int i = 0; i < obj.n; i++) {
		for (int j = 0; j < obj.m; j++) {
			obj.arr[i][j] -= temp.arr[i][j];
		}
	}
	return obj;
}
Matrix Matrix::operator* (const Matrix &temp) {
	Matrix ans = Matrix(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				ans.arr[i][j] = ans.arr[i][j] + arr[i][k] * temp.arr[k][j];
			}
		}
	}
	return ans;
}

Matrix Matrix::copy() {
	Matrix obj = Matrix(n, m);
	for (int i = 0; i < obj.n; i++) {
		for (int j = 0; j < obj.m; j++) {
			obj.arr[i][j] = arr[i][j];
		}
	}
	return obj;
}
Matrix Matrix::operator* (const double &temp) {
	Matrix obj = copy();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			obj.arr[i][j] *= temp;
		}
	}
	return obj;
}

double* Matrix::operator[](int x) {
	return arr[x];
}

istream& operator >>(istream& stream, Matrix &temp) {
	for (int i = 0; i < temp.n; i++) {
		for (int j = 0; j < temp.m; j++) {
			stream >> temp.arr[i][j];
		}
	}
	return stream;
}

ostream& operator <<(ostream& stream, Matrix &temp) {
	for (int i = 0; i < temp.n; i++) {
		for (int j = 0; j < temp.m; j++) {
			stream << temp.arr[i][j] << " ";
		}
		stream << endl;
	}
	return stream;
}
void Matrix::operator ~() {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < m; j++) {
			swap(arr[i][j], arr[j][i]);
		}
	}
}
void Matrix::gauss_method(double *ans) {
	if (m - n != 1) {
		cout << "invalid matrix for Gauss method" << endl;
	}
	else {
		for (int i = 0; i < m - 2; i++) {
			for (int j = i + 1; j < n; j++) {
				double koef = -arr[j][i] / arr[i][i];
				for (int k = i; k < m; k++) {
					arr[j][k] = arr[i][k] * koef + arr[j][k];
				}
			}
		}
		if (arr[n - 1][n - 1] == 0) {
			cout << "no solutions" << endl;
		}
		else {
			for (int i = m - 2; i >= 1; i--) {
				for (int j = i - 1; j >= 0; j--) {
					double koef = -arr[j][i] / arr[i][i];
					for (int k = m - 1; k >= i; k--) {
						arr[j][k] = arr[i][k] * koef + arr[j][k];
					}
				}
			}
			for (int i = 0; i < n; i++) {
				ans[i] = arr[i][m - 1] / arr[i][i];
			}
		}
	}
}

bool Matrix::symmetry() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i][j] != arr[j][i]) {
				return false;
			}
		}
	}
	return true;
}

void Matrix::jacobi(double *ans) {
	double** turning = new double*[n];
	double** temp = new double*[n];
	for (int i = 0; i < n; i++) {
		turning[i] = new double[n];
		temp[i] = new double[n];
		for (int j = i + 1; j < n; j++) {
			turning[i][j] = temp[i][j] = 0;
		}
	}
	double precision = 1;
	int x, y;
	double max;
	while (precision > esp) {
		x = 0;
		y = 0;
		max = 0.0;
		precision = 0.0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				precision = precision + arr[i][j] * arr[i][j];
			}
		}
		precision = sqrt(2 * precision);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (fabs(arr[i][j]) > max) {
					max = fabs(arr[i][j]);
					x = i;
					y = j;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				turning[i][j] = 0;
				temp[i][j] = 0;
			}
			turning[i][i] = 1;
		}
		if (arr[x][x] == arr[y][y]) {
			turning[x][x] = turning[y][y] = turning[y][x] = sqrt(2.0) / 2.0;
			turning[x][y] = -sqrt(2.0) / 2.0;
		}
		else {
			double koef = 0.5 * atan((2.0 * arr[x][y]) / (arr[x][x] - arr[y][y]));
			turning[x][x] = turning[y][y] = cos(koef);
			turning[x][y] = -sin(koef);
			turning[y][x] = sin(koef);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					temp[i][j] = temp[i][j] + turning[k][i] * arr[k][j];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = 0.0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					arr[i][j] = arr[i][j] + temp[i][k] * turning[k][j];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		ans[i] = arr[i][i];
	}
}

double Matrix::scalar(Matrix &obj, int row, double* u) {
	double res = 0;
	for (int i = 0; i < n; i++) {
		res = res + obj.arr[row][i] * u[i];
	}
	return res;
}

double Matrix::norma(Matrix obj, int row) {
	double res = 0;
	for (int i = 0; i < n; i++) {
		res = res + obj.arr[row][i] * obj.arr[row][i];
	}
	res = sqrt(res);
	return res;
}

double Matrix::len(double* u) {
	double res = 0;
	for (int i = 0; i < n; i++) {
		res = res + u[i] * u[i];
	}
	res = sqrt(res);
	return res;
}

double* Matrix::kachmazh() {
	Matrix obj = Matrix(n, m);
	for (int i = 0; i < obj.n; i++) {
		for (int j = 0; j < obj.m; j++) {
			obj.arr[i][j] = arr[i][j];
		}
	}
	int j = 0;
	double precision = 1;
	double* u = new double[n];
	for (int i = 0; i < n; i++) {
		u[i] = 1;
	}

	while (precision > esp) {
		j++;
		j %= n;
		double koef = (obj.arr[j][m - 1] - scalar(obj, j, u)) / (norma(obj, j)*norma(obj, j));
		double len1 = len(u);
		for (int i = 0; i < n; i++) {
			u[i] = u[i] + obj.arr[j][i] * koef;
		}
		double len2 = len(u);
		precision = fabs(len1 - len2);
	}
	return u;
}
