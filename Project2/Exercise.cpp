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



int main() {

	int arr[] = { 2,3,5 };
	int arr2[] = { 4,1,0 };

	cout<<ProductoP(arr, arr2, 3)<<endl;



	return 0;
}