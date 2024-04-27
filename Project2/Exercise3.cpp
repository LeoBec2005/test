#include <iostream>
using namespace std;

//Leonardo Becerra Reymer

int ProductoP(int* a, int* b, int n) {
	int* p = a;
	int* q = b;
	int suma = 0;

	while (p < a + n) {
		suma = ((*p) * (*q)) + suma;
		p++;
		q++;
	}
	return suma;
}


int* getColumn(int** mat, int f, int c, int x) {
	int* arr = new int[f];
	int** p = mat;
	int* q = 0;
	int* r = arr;

	while (p < mat + f) {
		*q = *q + x;
		*r = *q;
		p++;
		r++;
	}
	return arr;
}


int** multMat(int** m1, int f1, int c1, int** m2, int f2, int c2) {
	if (c1 != f2) {
		return 0;
	}
	
	int** r = new int* [f1];
	for (int i = 0; i < f1; i++) {
		r[i] = new int[c2];
	}
	int** pr = r;
	int* qr = 0;
	int** pm1 = m1;
	int cm2 = 0;

	while (pr < r + f1) {
		qr = *pr;
		int* fil = *pm1;
		while (qr < *pr + c2) {
			int* col = getColumn(m2, f2, c2, cm2);
			*qr = ProductoP(*pm1, col, f2);
			qr++;
			cm2++;
		}
		pr++;
		pm1++;
	}
	return r;
}

int main() {



	return 0;
}