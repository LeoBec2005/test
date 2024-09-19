#include <iostream>
using namespace std;

template<class T>
struct Nodo {
    T value;
    Nodo* next;
    Nodo(T v, Nodo<T>* n = nullptr) {
        value = v;
        next = n;
    }
};

template<class T, class U>
struct ListaEnlazada {
    Nodo<T>* head = nullptr;
    U comparador;

    void add(T v) {
        Nodo<T>* nuevoNodo = new Nodo<T>(v);
        if (head == nullptr) {
            head = nuevoNodo;
            return;
        }

        Nodo<T>* pos;
        if (find(v, pos)) {
            delete nuevoNodo;
            return;
        }

        Nodo<T>* actual = head;
        Nodo<T>* previo = nullptr;

        while (actual != nullptr && comparador(actual->value, v)) {
            previo = actual;
            actual = actual->next;
        }

        if (previo == nullptr) {
            nuevoNodo->next = head;
            head = nuevoNodo;
        }
        else {
            previo->next = nuevoNodo;
            nuevoNodo->next = actual;
        }
    }

    void del(T v) {
        if (head == nullptr) return;

        if (head->value == v) {
            Nodo<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Nodo<T>* actual = head;
        Nodo<T>* previo = nullptr;

        while (actual != nullptr && actual->value != v) {
            previo = actual;
            actual = actual->next;
        }

        if (actual == nullptr) return;

        previo->next = actual->next;
        delete actual;
    }

    bool find(T v, Nodo<T>*& pos) {
        pos = head;
        while (pos != nullptr) {
            if (pos->value == v) {
                return true;
            }
            pos = pos->next;
        }
        return false;
    }

    void print() {
        Nodo<T>* actual = head;
        while (actual != nullptr) {
            cout << actual->value << " -> ";
            actual = actual->next;
        }
        cout << "NULL" << endl;
    }
};

struct Ascendente {
    template<class T>
    bool operator()(T a, T b) {
        return a < b;
    }
};

struct Descendente {
    template<class T>
    bool operator()(T a, T b) {
        return a > b;
    }
};

int main() {
    ListaEnlazada<int, Ascendente> listaAsc;

    listaAsc.add(10);
    listaAsc.add(5);
    listaAsc.add(15);
    listaAsc.add(10);

    listaAsc.print();

    listaAsc.del(5);
    listaAsc.print();

    ListaEnlazada<int, Descendente> listaDesc;

    listaDesc.add(10);
    listaDesc.add(5);
    listaDesc.add(15);
    listaDesc.add(10);

    listaDesc.print();

    return 0;
}
