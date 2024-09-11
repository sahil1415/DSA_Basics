#include<iostream>
using namespace std;
class circularDeque{
    public:
      int* arr;
      int front;
      int rear;
      int size;
    
    circularDeque(int size){
        this->size = size;
        arr = new int[size];
        rear = -1;
        front = -1;
    }

    void push_back(int value){
         if(front == 0 && rear == size-1 || (rear == front-1)){
            cout<<"OverFlow"<<endl;
        }
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = value;
        }
        else if (rear == size-1 && front != 0){ // circular nature
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear++;
            arr[rear] = value;
        }
    }
    void push_front(int value){
        if(front == 0 && rear == size-1 || (front == rear+1)){
            cout<<"Queue Overflow"<<endl;
        }
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front] = value;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
            arr[front] = value;
        }
        else{
            front--;
            arr[front] = value;
        }
    }
    void pop_back(){
        if(rear == -1 && front == -1){
            cout<<"Queue underflow"<<endl;
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(rear == 0 && front != size-1){ // circular case
            arr[rear] = -1;
            rear = size-1;
        }
        else{
            arr[rear] = -1;
            rear--;
        }
    }
    void pop_front(){
        if(front == -1 && rear == -1){
            cout<<"Under Flow"<<endl;
        }
        else if(front == rear){
            arr[front] = -1;
            rear = -1;
            front = -1;
        }
        else if(front == size-1){ // circular nature
            arr[front] = -1;
            front = 0;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }
    void print(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    circularDeque cdq(5);
    cdq.push_back(10);
    cdq.push_back(20);
    cdq.push_back(30);
    cdq.push_back(40);
    cdq.push_front(300);
    cdq.pop_front();
    cdq.pop_front();
    cdq.pop_front();
    cdq.push_front(100);
    cdq.push_front(200);
    cdq.push_back(500);
    cdq.print();
    
return 0;
}