#include <iostream>
using namespace std;

int** BinMat(int f, int c) {

	int** r = new int* [f];
	for (int i = 0; i < f; i++) {
		r[i] = new int[c];
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < f; j++) {
			r[i][j] = 0;
		}
	}
	return r;
}

void switch1(int** mat, int f, int c,int f1,int c1) {
	int** p = mat;
	int q = 0;

}

bool check_row(int** mat, int f, int c) {
	return 0;
}

bool check_column(int** mat, int f, int c) {
	return 0;
}


int main() {


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << *(*BinMat(3, 3) + i)+j << endl;
		}
	}

	return 0;
}