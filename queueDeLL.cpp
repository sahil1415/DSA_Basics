#include<iostream>
using namespace std;

class node{
    public:

    int data;
    node* next;
    node* prev;

    node(int value){
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DEqueue{
    node* front;
    node* rear;

    public:
    DEqueue(){
        front = NULL;
        rear = NULL;
    }

    bool isEmpty(){
        if(rear == NULL){
            return true;
        }
        return false;
    }

    void push_back(int value){
        node* newNode = new node(value);
        if(isEmpty()){
            front = rear = newNode;
        }
        else{
            rear -> next = newNode;
            newNode -> prev = rear;
            rear = newNode;
        }
    }

    int pop_front(){
        if(isEmpty()){
            cout<<"DEqueue Underflow"<<endl;
        }
        int element = front -> data;
        if(front == rear){
            delete front;
            front = rear = NULL;
        }
        else{
            node* temp = front;
            front = front -> next;
            delete temp;
        }
        return element;
    }   

    void push_front(int value){
        node* newNode = new node(value);
          if(isEmpty()){
            rear = front = newNode;
        }
        else{
            node* temp = front;
            newNode ->next  = temp;
            temp -> prev = newNode;
            front = newNode;
        }
    }

    int pop_back(){
        if(isEmpty()){
            cout<<"Queue Underfolow"<<endl;
        }
        int element = rear -> data;
        if(front == rear){
            delete front;
            front = rear = NULL;
        }
        else{
            node* temp = rear;
            rear = rear -> prev;
            rear -> next = NULL;
            delete temp;
        }
        return element;
    }

    void traversalDEqueue(){
        while(!isEmpty()){
            cout<<pop_front()<<" ";
        }
        cout<<endl;
    }
};

int main(){
    DEqueue de;
    de.push_back(10);
    de.push_back(20);
    de.push_back(30);
    de.push_back(40);
    
    de.push_front(9);
    de.push_front(8);
    de.push_front(7);
    de.push_front(6);

    de.pop_front();
    de.pop_back();

    de.traversalDEqueue();
}