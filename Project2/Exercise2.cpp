#include <iostream>
using namespace std;

int* getColumn(int** mat, int f, int c, int x) {
	int* arr = new int[f];
	int** p = mat;
	int* q = 0;
	int* r = arr;
	

	while(p < mat+f) {
		*q = *q + x;
		*r = *q;
		p++;
		r++;
	}
	return arr;
}

int main() {

	

	int** mat = new int* [3];
	for (int i = 0; i < 3; i++){
		mat[i] = new int[3];
	}
		

	int mat[][] = { {1,2,3},{4,5,6,},{6,7,8} };


	getColumn(mat,3,3,1)







	return 0;
}