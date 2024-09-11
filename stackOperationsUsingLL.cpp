#include<iostream>
using namespace std;

class stack{
    public:
    int data;
    stack* next;

    // constructor so that we can  create a node whenever we want
    // automatically initializes values whenever we create an object
    stack(int value){
        data = value;
        next = NULL;
    }
};
bool empty(stack* top){
    if(top == NULL){
        return true;
    }
    return false;
}
void push(stack* &top, int value){
    stack* newNode = new stack(value);
    if(top == NULL){
        top = newNode;
        newNode ->next = NULL;
    }
    newNode -> next = top;
    top = newNode;
}

int  pop(stack** top){
    if(empty(*top)){
        cout<<"Stack UnderFlow"<<endl;
        return 0;
    }
    else{
        int n = (*top) -> data;
        (*top) = (*top) -> next;
        return n;
    }
}
int  topElement(stack* top){
    return top->data;
}
void traversingStack(stack* top){
    stack* temp = top;
    while(!empty(top)){
        cout<<topElement(top)<<" ";
        pop(&top);
    }
    cout<<endl;
}

int main(){
    stack* top = NULL;
    cout<<"Is stack empty-"<<empty(top)<<endl;
    push(top,10);
    push(top,20);
    push(top,30);
    cout<<"Is stack empty-"<<empty(top)<<endl;
    cout<<"Top Element - "<<topElement(top)<<endl;
    cout<<"Element popped -"<<pop(&top)<<endl;
    cout<<"Element popped -"<<pop(&top)<<endl;
    cout<<"Element popped -"<<pop(&top)<<endl;
    push(top,10);
    push(top,20);
    push(top,30);
    push(top,40);
    push(top,50);
    push(top,60);
    traversingStack(top);
}
