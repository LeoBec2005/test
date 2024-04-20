#include <iostream>
using namespace std;

int seq(int arr[], int n) {

	int* p = arr;
	int* q = arr + n-1;
	int count = 0;
	int prev = 2147483647;

	while ((p != q) || (*p >= prev) || (*q >= prev)) {
		if ((*p < *q) && (*p < prev)) {
			p++;
			count++;
			prev = *p;
		}
		if ((*q < *p) && (*q < prev)) {
			q--;
			count++;
			prev = *q;
		}
	}
	return count;
}

int main() {
	int arr[] = { 4,3,1,5,2 };

	cout << seq(arr, 5) << endl;


	return 0;
}