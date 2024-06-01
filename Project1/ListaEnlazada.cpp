#include <iostream>

// Definición de la clase Node
template<typename T>
class Node {
public:
    // Constructor
    Node(T data) : data(data), next(nullptr) {}

    // Getter y Setter
    T getData() const { return data; }
    void setData(T newData) { data = newData; }

    Node<T>* getNext() const { return next; }
    void setNext(Node<T>* newNext) { next = newNext; }

private:
    T data;
    Node<T>* next;
};

// Definición de la clase LinkedList
template<typename T>
class LinkedList {
private:
    Node<T>* root;

public:
    // Constructor
    LinkedList() : root(nullptr) {}

    // Destructor
    ~LinkedList() {
        Node<T>* current = root;
        Node<T>* nextNode;

        while (current != nullptr) {
            nextNode = current->getNext();
            delete current;
            current = nextNode;
        }
    }

    // Método para imprimir la lista
    void print_list() const {
        Node<T>* temp = root;
        while (temp != nullptr) {
            std::cout << temp->getData() << " -> ";
            temp = temp->getNext();
        }
        std::cout << "nullptr" << std::endl;
    }

    // Método para insertar al frente
    void push_front(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->setNext(root);
        root = newNode;
    }

    // Método para insertar al final
    void push_back(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node<T>* temp = root;
            while (temp->getNext() != nullptr) {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
    }

    int size() {
        Node<T>* temp = root;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->getNext();
        }
        return count;
    }

    bool IsEmpty() {
        Node<T>* temp = root;
        if (temp== nullptr) {
            return 1;
        }
        return 0;
    }

    // Método para insertar en una posición específica
    void insert_at(int index, T data) {
        if (index < 0) {
            std::cout << "Índice inválido" << std::endl;
            return;
        }

        Node<T>* newNode = new Node<T>(data);

        if (index == 0) {
            newNode->setNext(root);
            root = newNode;
            return;
        }

        Node<T>* temp = root;
        for (int i = 0; i < index - 1; i++) {
            if (temp == nullptr) {
                std::cout << "Índice fuera de rango" << std::endl;
                delete newNode;
                return;
            }
            temp = temp->getNext();
        }

        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
    }

    // Método para insertar después de un nodo específico
    void insert_after(Node<T>* prev_node, T data) {
        if (prev_node != nullptr) {
            Node<T>* newNode = new Node<T>(data);
            newNode->setNext(prev_node->getNext());
            prev_node->setNext(newNode);
        }
        else {
            std::cout << "Nodo no encontrado." << std::endl;
        }
    }

    // Método para eliminar del frente
    void pop_front() {
        if (root != nullptr) {
            Node<T>* temp = root;
            root = root->getNext();
            delete temp;
        }
    }

    void pop_back() {
        if (root != nullptr) {
            if (root->getNext() == nullptr) {
                delete root;
                root = nullptr;
            }
            else {
                Node<T>* temp = root;
                while (temp->getNext()->getNext() != nullptr) {
                    temp = temp->getNext();
                }
                delete temp->getNext();
                temp->setNext(nullptr);
            }
        }
    }

    void clear(){
        Node<T>* temp = root;
        while (temp != nullptr) {
            pop_front();
        }
    }



    // Método para buscar un nodo
    Node<T>* search(T data) const {
        Node<T>* temp = root;
        while (temp != nullptr) {
            if (temp->getData() == data) {
                return temp;
            }
            temp = temp->getNext();
        }
        return nullptr;
    }

    // Método para intercambiar los datos de dos nodos
    void swap_data(Node<T>* a, Node<T>* b) {
        if (a != nullptr && b != nullptr) {
            T temp = a->getData();
            a->setData(b->getData());
            b->setData(temp);
        }
    }

    // Método para encontrar el nodo anterior
    Node<T>* find_previous_node(Node<T>* node) {
        if (node == nullptr || node == root) return nullptr;
        Node<T>* temp = root;
        while (temp != nullptr && temp->getNext() != node) {
            temp = temp->getNext();
        }
        return temp;
    }

    // Método para eliminar un nodo
    void delete_node(Node<T>* node) {
        if (node == nullptr) return;

        if (node == root) {
            root = root->getNext();
            delete node;
            return;
        }

        Node<T>* prev = find_previous_node(node);
        if (prev != nullptr) {
            prev->setNext(node->getNext());
            delete node;
        }
    }

    // Método para intercambiar dos nodos
    void swap_nodes(Node<T>* a, Node<T>* b) {
        if (a == nullptr || b == nullptr || a == b) return;

        Node<T>* prev_a = find_previous_node(a);
        Node<T>* prev_b = find_previous_node(b);

        if (prev_a == nullptr && prev_b == nullptr) {
            return;
        }

        // Si uno de los nodos es el nodo raíz
        if (a == root) {
            root = b;
        }
        else {
            prev_a->setNext(b);
        }

        if (b == root) {
            root = a;
        }
        else {
            prev_b->setNext(a);
        }

        Node<T>* temp = a->getNext();
        a->setNext(b->getNext());
        b->setNext(temp);
    }
};

int main() {
    LinkedList<float>* mi_lista = new LinkedList<float>;

    mi_lista->push_front(3.2);
    mi_lista->push_back(4.5);
    mi_lista->push_front(1.1);
    mi_lista->push_back(6.7);

    Node<float>* encontrado = mi_lista->search(4.5);
    if (encontrado != nullptr) {
        std::cout << "Encontrado: " << encontrado->getData() << std::endl;
    }
    else {
        std::cout << "No encontrado" << std::endl;
    }

    mi_lista->insert_after(encontrado, 5.2);
    mi_lista->print_list();

    Node<float>* a = mi_lista->search(3.2);
    Node<float>* b = mi_lista->search(5.2);

    if (a != nullptr) std::cout << "Nodo A: " << a->getData() << std::endl;
    if (b != nullptr) std::cout << "Nodo B: " << b->getData() << std::endl;

    mi_lista->swap_nodes(a, b);
    mi_lista->print_list();

    mi_lista->delete_node(a);
    mi_lista->print_list();

    std::cout<<mi_lista->size()<<std::endl;
    std::cout << mi_lista->IsEmpty() << std::endl;

    mi_lista->clear();
    std::cout << mi_lista->IsEmpty() << std::endl;
    mi_lista->print_list();
    delete mi_lista;

    return 0;
}