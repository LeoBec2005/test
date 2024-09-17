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

template <class T, class C>
struct bubblesort {
	C op;
	void operator() (T* ini, T* fin) {
		T* o = fin;

		bool sigue = true;
		while ((ini < fin) && sigue) {
			sigue = false;
			for (T* p = ini; p < fin; p++) {
				if (op(*p, *(p + 1))) {
					swap(*p, *(p + 1));
					sigue = true;
				}
			}
			fin--;
		}

		for (T* i = ini; i <= o; i++) {
			cout<<" ["<< *i << "] ";
		}
		cout << "\n";
	}
};



int main() {
	int arr1[] = { 7,9,1,4,0};
	bubblesort<int, ascendente> a;
	a(arr1, arr1 + 4);

	float arr2[] = { 9.9,0.1,0.001,5.21 };
	bubblesort<float, descendente> b;
	b(arr2, arr2 + 3);

}