#include <iostream>
#include <algorithm>

template <class T>
struct Nodo {
    T value[5];
    Nodo* next;
    T* top;

    Nodo() {
        top = value;
        next = nullptr;
    }

    bool isFull() {
        return (top - value) == 5;
    }

    bool isEmpty() {
        return top == value;
    }

    void insertValue(T val) {
        if (!isFull()) {
            *top = val;
            top++;
            std::sort(value, top);
        }
    }

    void deleteAt(int index) {
        if (index < 0 || index >= (top - value)) return;

        for (int i = index; i < (top - value) - 1; ++i) {
            value[i] = value[i + 1];
        }
        top--;
    }
};

template <class T>
class LinkedList {
private:
    Nodo<T>* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void add(T val) {
        if (!head) {
            head = new Nodo<T>();
        }

        Nodo<T>* current = head;
        while (current->next && current->isFull()) {
            current = current->next;
        }

        if (current->isFull()) {
            Nodo<T>* newNodo = new Nodo<T>();
            newNodo->insertValue(val);
            current->next = newNodo;
        } else {
            current->insertValue(val);
        }
    }

    void del(T val) {
        if (!head) return;

        Nodo<T>* current = head;
        Nodo<T>* prev = nullptr;

        while (current) {
            T* pos = std::find(current->value, current->top, val);

            if (pos != current->top) {
                int index = pos - current->value;
                current->deleteAt(index);

                Nodo<T>* nextNode = current->next;

                while (nextNode) {
                    current->insertValue(nextNode->value[0]);
                    nextNode->deleteAt(0);
                    current = nextNode;
                    nextNode = nextNode->next;
                }
                break;
            }

            prev = current;
            current = current->next;
        }

        current = head;
        Nodo<T>* last = nullptr;

        while (current) {
            if (current->isEmpty() && last) {
                last->next = current->next;
                delete current;
                break;
            }
            last = current;
            current = current->next;
        }
    }

    void print() {
        Nodo<T>* current = head;

        while (current) {
            for (T* p = current->value; p < current->top; ++p) {
                std::cout << *p << " ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool find(T val) {
        Nodo<T>* current = head;

        while (current) {
            if (std::binary_search(current->value, current->top, val)) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    LinkedList<int> lista;

    lista.add(3);
    lista.add(1);
    lista.add(4);
    lista.add(2);
    lista.add(5);
    lista.add(6);
    lista.add(9);
    lista.print(); 

    lista.del(1); 
    lista.print();  

    lista.del(4); 
    lista.print(); 

    return 0;
}
