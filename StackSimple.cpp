#include<iostream>
using namespace std;

class stack{
    int data;
    stack* next;

    public:
    stack* top;
    stack(){
        top = NULL;
    }
    stack(int value){
        data = value;
        next = NULL;
    }

    bool empty(){
        if(top == NULL){
            return true;
        }
        return false;
    }
    void push(int value){
        stack * newNode = new stack(value);
        if(top == NULL){
            top = newNode;
        }
        stack* temp  = top;
        newNode -> next = temp;
        top = newNode;
    }

    int pop(){
        if(empty()){
            cout<<"Stack UnderFlow"<<endl;
        }
        stack* temp = top;
        int n = temp -> data;
        top = top -> next;
        delete temp;
        return n;
    }

    int peek(){
        return top -> data;
    }
    // void traversingStack(){
    //     while(top != NULL){
    //         cout<<top->data<<" ";
    //         top = top-> next;
    //     }
    //     cout<<endl;
    // }
};
int main(){
    stack s;
    cout<<"Is stack Empty - "<<s.empty()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"Is stack Empty - "<<s.empty()<<endl;
    cout<<"Element popped - "<<s.pop()<<endl;
    cout<<"Element popped - "<<s.pop()<<endl;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<"Peak element - "<<s.peek()<<endl;
    // s.traversingStack();
}