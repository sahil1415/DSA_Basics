#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = NULL;
    }
};

class queue{
    node* front;
    node* last;
    public:
    queue(){
        front = NULL;
        last = NULL;
    }

    bool isEmpty(){
        return last == NULL;
    }

    void enqueue(int value){
        node* newNode = new node(value);
        if(isEmpty()){
            front = last = newNode;
        }
        last->next = newNode;
        last = newNode;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
        }
        node* temp = front;
        front = front -> next;
        delete temp;
        // cout<<"Element dequed"<<endl;
    }
    int frontElement(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
        }
        return front->data;
    }
    void traversalQueue(){
        while(!isEmpty()){
            cout<<frontElement()<<" ";
            dequeue();
        }
    }
};

int main(){
    queue q;
    cout<<"Is queue empty - "<<q.isEmpty()<<endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<"Is queue empty - "<<q.isEmpty()<<endl;
    cout<<"Front Element - "<<q.frontElement()<<endl;
    q.dequeue();
    cout<<"Front Element - "<<q.frontElement()<<endl;
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout<<"Traversing the queue - "<<endl;
    q.traversalQueue();
}
