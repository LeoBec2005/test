#include <iostream>

template <typename T>
struct Nodo {
    T value[5]; 
    Nodo* next; 
    T* top;    

    Nodo() {
        top = value; 
        next = nullptr;
    }

    bool lleno() {
        return (top - value) == 5;
    }

    // Inserta un valor del arr
    bool insertarOrdenado(T v) {
        if (lleno()) return false; // No hay espacio en este nodo

        int i = 0;
        while (i < (top - value) && value[i] < v) {
            i++;
        }

        for (int j = (top - value); j > i; j--) {
            value[j] = value[j - 1];
        }

        value[i] = v;
        top++;
        return true;
    }

    // Elimina valor del arr
    bool eliminar(T v) {
        int i = 0;
        while (i < (top - value) && value[i] != v) {
            i++;
        }

        if (i == (top - value)) {
            return false; 
        }
        for (int j = i; j < (top - value) - 1; j++) {
            value[j] = value[j + 1];
        }

        top--; 
        return true;
    }

    void imprimir() {
        for (int i = 0; i < (top - value); i++) {
            std::cout << value[i] << " ";
        }
    }
};

template <typename T>
class Lista {
    Nodo<T>* head;

public:
    Lista() {
        head = new Nodo<T>();
    }

//Inserta nodo
    void insertarOrdenado(T v) {
        Nodo<T>* actual = head;

        // Insertar en el nodo adecuado o crear uno nuevo si está lleno
        while (actual->lleno()) {
            if (actual->next == nullptr) {
                actual->next = new Nodo<T>();
            }
            actual = actual->next;
        }

        if (!actual->insertarOrdenado(v)) {
            // Si el nodo está lleno, insertar en el siguiente
            if (actual->next == nullptr) {
                actual->next = new Nodo<T>();
            }
            actual->next->insertarOrdenado(v);
        }
    }

//Elimina nodo
    void eliminar(T v) {
        Nodo<T>* actual = head;
        while (actual != nullptr) {
            if (actual->eliminar(v)) {
                break;
            }
            actual = actual->next;
        }
    }

    void imprimir() {
        Nodo<T>* actual = head;
        while (actual != nullptr) {
            actual->imprimir();
            actual = actual->next;
            if (actual != nullptr) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Lista<int> lista;

    lista.insertarOrdenado(4);
    lista.insertarOrdenado(6);
    lista.insertarOrdenado(2);
    lista.insertarOrdenado(7);
    lista.insertarOrdenado(8);
    lista.insertarOrdenado(9);

    lista.imprimir(); 


    lista.eliminar(2);
    lista.imprimir(); 


    lista.insertarOrdenado(5);
    lista.imprimir();

    return 0;
}