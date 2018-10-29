#include<iostream>

using namespace std;

class Matrix {
private:
	int n, m;
	double **arr = new double*[n];
public:
	Matrix(int p_n, int p_m) {
		n = p_n;
		m = p_m;
		for (int i = 0; i < n; i++) {
			arr[i] = new double[m];
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0;
			}
		}
	}
	Matrix() = default;
	Matrix operator= (const Matrix &temp) {
		Matrix obj = *this;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				obj.arr[i][j] = temp.arr[i][j];
			}
		}
		return obj;
	}
	bool operator== (Matrix &temp) {
		if (n == temp.n && m == temp.m) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (arr[i][j] != temp.arr[i][j]) {
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
	Matrix operator+ (const Matrix &temp) {
		Matrix obj = Matrix(n, m);
		for (int i = 0; i < obj.n; i++) {
			for (int j = 0; j < obj.m; j++) {
				obj.arr[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				obj.arr[i][j] += temp.arr[i][j];
			}
		}
		return obj;
	}
	Matrix operator- (const Matrix &temp) {
		Matrix obj = Matrix(n, m);
		for (int i = 0; i < obj.n; i++) {
			for (int j = 0; j < obj.m; j++) {
				obj.arr[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < obj.n; i++) {
			for (int j = 0; j < obj.m; j++) {
				obj.arr[i][j] -= temp.arr[i][j];
			}
		}
		return obj;
	}
	Matrix operator* (const Matrix &temp) {
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
	Matrix operator* (const double &temp) {
		Matrix obj = Matrix(n, m);
		for (int i = 0; i < obj.n; i++) {
			for (int j = 0; j < obj.m; j++) {
				obj.arr[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				obj.arr[i][j] *= temp;
			}
		}
		return obj;
	}
	friend istream& operator >>(istream& stream, Matrix &temp) {
		for (int i = 0; i < temp.n; i++) {
			for (int j = 0; j < temp.m; j++) {
				stream >> temp.arr[i][j];
			}
		}

		return stream;
	}
	friend ostream& operator <<(ostream& stream, Matrix &temp) {
		for (int i = 0; i < temp.n; i++) {
			for (int j = 0; j < temp.m; j++) {
				stream << temp.arr[i][j] << " ";
			}
			stream << endl;
		}
		return stream;
	}
	void operator ~() {
		for (int i = 0; i < n; i++) {
			for (int j = i; j < m; j++) {
				swap(arr[i][j], arr[j][i]);
			}
		}
	}
	void gauss_method() {
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
					cout << "x" << i + 1 << " = " << arr[i][m - 1] / arr[i][i] << ";" << endl;
				}
			}
		}
	}
};

int main() {

	int n, m;
	cin >> n >> m;
	Matrix matrix = Matrix(n, m);
	cin >> matrix;

	Matrix matrix2 = Matrix(n, m);
	cin >> matrix2;

	Matrix x = matrix + matrix2 + matrix - matrix2 * 4.0;
	cout << endl;
	cout << x;
	cout << matrix;
	cout << matrix2;
	system("pause");
	return 0;

}