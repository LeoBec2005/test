#include <iostream>

// Definición de la clase Node
template<typename T>
class Node {
public:
    // Constructor
    Node(T data) : data(data), next(nullptr), prev(nullptr) {}

    // Getter y Setter
    T getData() const { return data; }
    void setData(T newData) { data = newData; }

    Node<T>* getNext() const { return next; }
    void setNext(Node<T>* newNext) { next = newNext; }

    Node<T>* getPrev() const { return prev; }
    void setPrev(Node<T>* newPrev) { prev = newPrev; }

private:
    T data;
    Node<T>* next;
    Node<T>* prev;
};

// Definición de la clase LinkedList
template<typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    // Constructor
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor
    ~DoubleLinkedList() {
        Node<T>* current = head;
        Node<T>* nextNode;

        while (current != nullptr) {
            nextNode = current->getNext();
            delete current;
            current = nextNode;
        }
    }

    // Método para imprimir la lista
    void print_list() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->getData() << " <-> ";
            temp = temp->getNext();
        }
        std::cout << "nullptr" << std::endl;
    }

    void print_reverse() const {
        Node<T>* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->getData() << " <-> ";
            temp = temp->getPrev();
        }
        std::cout << "nullptr" << std::endl;
    }

    // Método para insertar al frente
    void push_front(T data) {
        Node<T>* newNode = new Node<T>(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        head->setPrev(newNode);
        newNode->setNext(head);
        head = newNode;
    }

    // Método para insertar al frente
    void push_back(T data) {
        Node<T>* newNode = new Node<T>(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
    int size() {
        Node<T>* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->getNext();
        }
        return count;
    }

    bool empty() {
        Node<T>* temp = head;
        if ((head == nullptr) && (tail == nullptr)) {
            return 1;
        }
        return 0;
    }
    void clear() {
        Node<T>* temp = head;
        while(head != nullptr){
            if (temp->getNext()->getNext() == nullptr) {
                delete temp->getNext;
                temp->getNext = nullptr;
                temp->getPrev;
            }
        }
        head = nullptr;
        tail = nullptr;
    }

    void pop_back() {
        if (head != nullptr) {
            if (head->getNext() == nullptr) {
                delete head;
                head = nullptr;
            }
            else {
                Node<T>* temp = head;
                while (temp->getNext()->getNext() != nullptr) {
                    temp = temp->getNext();
                }
                delete temp->getNext();
                temp->setNext(nullptr);
            }
        }

    }

    void getBack() {

}
};

int main() {
    DoubleLinkedList<int>* mi_lista = new DoubleLinkedList<int>;

    mi_lista->push_front(1);
    mi_lista->push_front(2);
    mi_lista->push_back(3);
    mi_lista->push_back(5);
    mi_lista->print_list();
    std::cout << mi_lista->size() << std::endl;
    std::cout << mi_lista->empty() << std::endl;
    mi_lista->print_list();
    mi_lista->print_reverse();
    mi_lista->clear();
    delete mi_lista;

    return 0;
}

