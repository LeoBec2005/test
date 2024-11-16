#include <iostream>

template <class T>
class Node {
    Node<T>* der = nullptr;
    Node<T>* izq = nullptr;
    T value;
};

template <class T>
class binary_tree {
    Node<T>* root = nullptr;
    void add() {
        Node<T>* new_node = new Node<T>;
        Node<T>* aux = root;
        if (aux == nullptr) {
            if (new_node->value > aux->value) {
                aux->der = new_node;
            }
            else {
                aux = aux->der;
                void add();
            }
            if (new_node->value < aux->value) {
                aux->der = new_node;
            }
            else {
                aux = aux->izq;
                void add();
            }
        }
    }

   

};

int main()
{
    std::cout << "Hello World!\n";


}

