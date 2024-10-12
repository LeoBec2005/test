#include <iostream>
using namespace std;

template<class T>
struct Nodo{
    T value;
    Nodo<T>* next;
};

template<class T>
struct Cola{
    Nodo<T>* head = nullptr;
    Nodo<T>* tail = nullptr;
    
    void push(T v){
        Nodo<T>* new_node = new Nodo<T>;
        new_node->value = v;
        new_node->next = nullptr; 

        if (head == nullptr) { 
            head = new_node;    
            tail = new_node;  
        } else {
            tail->next = new_node; 
            tail = new_node; 
        }
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
        if(head == nullptr)return;
        Nodo<T>* aux = head;
        head = head->next;
        delete aux;
    }


};

int main(){
    cout<<"xd"<<endl;
    Cola<int> cola1;
    cola1.push(5);
    cola1.push(7);
    cola1.push(10);
    cola1.push(14);
    cola1.push(2);
    
    cola1.print();
    
    cola1.pop();
    cola1.pop();
    
    cola1.print();
    

    
return 0;    
}
