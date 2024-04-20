#include <iostream>
using namespace std;

int* BinarySearch(int arr[],int n,int v) {

	int* p = arr;
	int* q = arr + n - 1;
	
	
	while(p <= q) {
		int* m = p + ((q - p) / 2);
		if (*m == v) {
			return m;
		}
		if (*m < v) {
			p = m + 1;
		}
		else {
			q = m - 1;
		}
	}

	return 0;
}

//void print_mat(int** mat,int raws,int columns)

int main() {
	int arr[] = { 2,4,5,20,24,96 };
	cout << *(BinarySearch(arr, 6, 20)) << endl;
	return 0;
}