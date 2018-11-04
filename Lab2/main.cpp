#include<iostream>
#include "Matrix.h"
#include <cstdio>
#include "bitmap_image.hpp"
#include <fstream>
#include <string>

using namespace std;

void read(double **a, string file_name) {
	bitmap_image image(file_name);
	const unsigned int height = image.height();
	const unsigned int width = image.width();
	for (std::size_t y = 0; y < height; ++y)
	{
		for (std::size_t x = 0; x < width; ++x)
		{
			rgb_t colour;

			image.get_pixel(x, y, colour);
			int temp;
			if (colour.blue > 0 || colour.red > 0 || colour.green > 0) {
				temp = 0;
			}
			else {
				temp = 1;
			}
			a[y][x] = temp;
		}
	}
}

void learn() {

	double **ans = new double*[50];
	double **mas = new double*[50];
	for (int i = 0; i < 50; i++) {
		ans[i] = new double[50];
		mas[i] = new double[50];
		for (int j = 0; j < 50; j++) {
			ans[i][j] = 0;
			mas[i][j] = 0;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int q = 0; q < 50; q++) {
			for (int w = 0; w < 50; w++) {
				ans[q][w] = 0;
				mas[q][w] = 0;
			}
		}
		for (int j = 1; j <= 10; j++) {
			char t = i + '0';
			string file_name = "";
			file_name += t;
			file_name += '-';
			if (j == 10) {
				file_name += '1';
				file_name += '0';
			}
			else {
				t = j + '0';
				file_name += t;
			}
			file_name += ".bmp";
			read(mas, file_name);
			for (int x = 0; x < 30; x++) {
				for (int y = 0; y < 15; y++) {
					if (mas[x][y] == 1) {
						ans[x][y] += 0.1;
					}
				}
			}
		}
		char t = i + '0';
		string out = "";
		out += t;
		out += ".txt";
		ofstream fout(out);
		for (int x = 0; x < 30; x++) {
			for (int y = 0; y < 15; y++) {
				fout << ans[x][y] << " ";
			}
			fout << endl;
		}
	}

}

int main() {
	cout << "if you want to recognize the number, press 1 else 0" << endl;
	int temp = 0;
	cin >> temp;
	if (temp) {
		//learn();
		double **mas = new double*[50];
		for (int i = 0; i < 50; i++) {
			mas[i] = new double[50];
			for (int j = 0; j < 50; j++) {
				mas[i][j] = 0;
			}
		}
		read(mas, "h.bmp");
		int is_number = 0;
		double max_koef = 0.0;
		for (int num = 0; num < 10; num++) {
			string file_name = "";
			char t = num + '0';
			file_name += t;
			file_name += ".txt";

			ifstream fin(file_name);
			double koef = 0.0;
			double temp;
			for (int i = 0; i < 30; i++) {
				for (int j = 0; j < 15; j++) {
					fin >> temp;
					koef = koef + mas[i][j] * temp;
				}
			}
			if (max_koef < koef) {
				max_koef = koef;
				is_number = num;
			}
		}
		cout << "is number: " << is_number << endl;
	}
	else {

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
	}
	system("pause");
	return 0;

}