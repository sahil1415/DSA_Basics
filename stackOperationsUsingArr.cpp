#include<iostream>
using namespace std;
class stack{
    int top;
    int *arr;
    int size;

    public:
    stack(){
        top = -1;
        size = 5;
        arr = new int(size);
    }

    bool isEmpty(){
        if(top <= -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(top >= size-1){
            return true;
        }
        return false;
    }

    void push(int value){
        if(isFull()){
            cout<<"Stack over flow"<<endl;
        }
        else{
            top++;
            arr[top] = value;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
        }
        top--;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return arr[top];
    }

    void traversingStack(){
        while(top>-1){
            cout<<peek()<<" ";
            pop();
        }
        cout<<endl;
    }
};

int main(){
    stack s;
    cout<<"Is stack empty - "<<s.isEmpty()<<endl;
    cout<<"Is stack full - "<<s.isFull()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<"Top element - "<<s.peek()<<endl;
    cout<<"Traversing the stack - "<<endl;
    s.traversingStack();
}