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
        Nodo<T>* pos = nullptr;
        if (find(v, pos)) {
            return;
        }

        Nodo<T>* nuevoNodo = new Nodo<T>(v);
        if (pos == nullptr) {
            nuevoNodo->next = head;
            head = nuevoNodo;
        } else {
            nuevoNodo->next = pos->next;
            pos->next = nuevoNodo;
        }
    }

    void del(T v) {
        Nodo<T>* pos = nullptr;
        if (!find(v, pos)) {
            return;
        }

        if (pos == nullptr) {
            Nodo<T>* temp = head;
            head = head->next;
            delete temp;
        } else if (pos->next != nullptr && pos->next->value == v) {
            Nodo<T>* temp = pos->next;
            pos->next = temp->next;
            delete temp;
        }
    }

    bool find(T v, Nodo<T>*& pos) {
        pos = nullptr;
        Nodo<T>* actual = head;

        while (actual != nullptr) {
            if (actual->value == v) {
                return true;
            }
            if (comparador(v, actual->value)) {
                return false;
            }
            pos = actual;
            actual = actual->next;
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
