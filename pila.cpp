#include <iostream>
using namespace std;

template <class T>
struct Nodo{
	T value;
	Nodo<T>* next;
};

template <class T>
struct Pila {
	Nodo<T>* head = nullptr;

	void push(T v) {
		Nodo<T>* new_node = new Nodo<T>;
		new_node->value = v;
		new_node->next = head;
		head = new_node;
	}

	void print() {
		Nodo<T>* aux = head;
		cout << "head -> ";
		while (aux != nullptr) {
			cout << aux->value<<" -> ";
			aux = aux->next;
		}
		cout << "null" << endl;;
	}

	void pop() {
		if (head == nullptr)return;
		Nodo<T>* aux = head;
		head = head->next;
		delete aux;

	}
};

int main() {
	Pila<int> pila;
	pila.push(2);
	pila.push(5);
	pila.push(6);
	pila.push(9);
	pila.print();
	
	pila.pop();
	pila.print();

	pila.pop();
	pila.print();

	return 0;
}



