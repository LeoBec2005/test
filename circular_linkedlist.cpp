#include <iostream>
using namespace std;

template<class T>
struct Nodo{
    T value;
    Nodo<T>* next;
};

template<class T>
struct Circular_linked_list{
    Nodo<T>* head = nullptr;
    
void add(T v,int pos){
    Nodo<T>* aux = head;
    int lenght = 0;
    while(aux != nullptr){
        aux = aux->next;
        lenght++;
    }
    
    Nodo<T>* new_node = new Nodo<T>;
    new_node->value = v;
    if(head == nullptr){
        head = new_node;
        new_node->next = head;
    }
    else{
    if(pos<lenght){
        Nodo<T>* aux1= head; 
            for(int i = 0;i <= pos;i++){
                aux1 = aux1->next;
            }
        new_node->next = aux->next;
        aux = new_node;
        }    
    else{
    cout<<"escribe una posicion valida para insertar"<<endl;    
        }
    }
}


void print() {
		Nodo<T>* aux = head;
		cout << "head -> ";
		do{
		    cout << aux->value<<" -> ";
			aux = aux->next;
		}while (aux->next != head);
		cout << " <- return" << endl;;
	}
    
    
};


int main(){

Circular_linked_list<int> list1;

list1.add(3,2);
list1.add(3,1);
list1.print();
    
    
return 0;    
}