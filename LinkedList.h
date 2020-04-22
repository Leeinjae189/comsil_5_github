#include<iostream>
#include<string>
using namespace std;

// Linked List Node
template <class T>
class Node{
public:
    T data;
    Node *link;
    Node(T element){
        data = element;
        link = 0; }
};

// Linked List Class
template <class T>
class LinkedList
{
protected:
    Node<T>* first;
    int current_size;
public:
    LinkedList() {
        first = 0;
        current_size = 0;
    };
    int GetSize() { return current_size; }; 
    void Insert(T element);
    virtual bool Delete(T& element); 
    void Print();
};

template <class T>
void LinkedList<T>::Insert(T element)
{ 
    Node<T> *newnode = new Node<T>(element);
    newnode->link = first;
    first = newnode;
    current_size++;
}

template <class T>
bool LinkedList<T>::Delete(T &element)
{
    if(first == 0) return false;
    Node<T> *current = first, *previous = 0;
    while(1){    
        if(current->link == 0)   
        {
            if(previous) previous->link = current->link;
            else first = first->link;
            break;
        }
        previous = current;
        current = current->link;
    }
    element = current->data;
    delete current;
    current_size--;
    return true;
}

template <class T>
void LinkedList<T>::Print()
{ 
	int i;
	Node<T>* temp = first;
	for(i=0;i<current_size;i++){
		cout<<"["<<i+1<<"|"<<temp->data<<"]";
		if(temp->link != NULL){
			cout<<"->";
			temp = temp->link;
		}
		else
			cout<<endl;
	}
}

template<class T>
class Stack:public LinkedList<T>
{ 
public:
	bool Delete(T &element);
};

template<class T>
bool Stack<T>::Delete(T &element)
{ 
    if(this->first==NULL) return false;
	Node<T>* temp =this-> first;
	element = this->first->data;
  
	this->first = this->first->link;

    delete temp;
    this-> current_size--;
    return true;		
};
