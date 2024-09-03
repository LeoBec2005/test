#include <iostream>
using namespace std;

struct ascendente {
	bool operator() (int a, int b) {
		return a > b;
	}
};

struct descendente {
	bool operator() (int a, int b) {
		return a < b;
	}
};

template <class T, class func_class>
struct bubblesort {
	void operator() (T* arr, int n,func_class functor) {
		T* p = arr;
		T* q = arr + 1;
		int lenght = n;

	while(lenght != 1){
		while(q < arr+lenght){
			if (functor(*p,*q)) {
				swap(*p, *q);
			}
			p++;
			q++;
		}
	p = arr;
	q = arr + 1;
	lenght--;
	}

	for (int i = 0; i < n; i++) {
		cout << "[" << *(arr+i) << "] ";
	}
	cout << endl;

	}
};


int main() {
	int length_arr1 = 6;
	int length_arr2 = 6;
	int* arr1 = new int[length_arr1]{5, 4, 12, 1, 2,1};
	float* arr2 = new float[length_arr2] {1.1, 3.42, 5.112, 0.32, 0.11,0.11};
	bubblesort<int,ascendente> array1;
	bubblesort<float, descendente> array2;
	array1(arr1, length_arr1, ascendente());
	array2(arr2, length_arr2, descendente());

	

	delete[] arr1;
	delete[] arr2;
}