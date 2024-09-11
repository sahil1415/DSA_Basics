#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int value){
        data = value;
        next = NULL;
    }
};

class circularQueue{
    node* front;
    node* rear;
    public:
    circularQueue(){
        front = NULL;
        rear = NULL;
    }
    bool isEmpty(){
        if(rear == NULL){
            return true;
        }
        return false;
    }

    void enQueue(int value){
        node* newNode = new node(value);
        if(isEmpty()){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        rear -> next = front;
    }
    int deQueue(){
        if(isEmpty()){
            cout<<"Queue UnderFlow"<<endl;
        }

        int element = front -> data;

        if(front == rear){
            delete front;
            front = rear = NULL;
        }
        else{
        node* temp = front;
        front = front -> next;
        rear -> next = front;
        delete temp;
        }
        return element;
    }
    int frontElement(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
        }
        return front->data;
    }
    int rearElement(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
        }
        return rear->data;
    }
};

int main(){
    circularQueue cq;
    cout<<"Is circular queue empty - "<<cq.isEmpty()<<endl;

    cq.enQueue(10);
    cout<<"Is circular queue empty - "<<cq.isEmpty()<<endl;
    cq.enQueue(20);
    cq.enQueue(30);
    cq.enQueue(40);
    cq.enQueue(50);

    

    cout<<"Front Element - "<<cq.frontElement()<<endl;
    cout<<"Reaar Element - "<<cq.rearElement()<<endl;

    cout<<"Dequeued element - "<<cq.deQueue()<<endl;
    cout<<"Dequeued element - "<<cq.deQueue()<<endl;
    cout<<"Dequeued element - "<<cq.deQueue()<<endl;
    cout<<"Dequeued element - "<<cq.deQueue()<<endl;
    cout<<"Dequeued element - "<<cq.deQueue()<<endl;

    cout<<"Is circular queue empty - "<<cq.isEmpty()<<endl;
}