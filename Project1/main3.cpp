#include <iostream>
using namespace std;

void print_mat(int* mat, int raws, int columns) {
	
	

	for (int* p = mat; p < mat +raws; p++) {
		for(int* q = p; q<mat +columns;q++){
			cout << *(*q+p) << endl;;
		}
	}


}


int main() {

	int mat[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	print_mat(*mat, 3, 3);
	
	return 0;
}
