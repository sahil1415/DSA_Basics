#include<iostream>
using namespace std;
class circularqueue{
    public:
    int* arr;
    int front;
    int rear;
    int size;

    circularqueue(int size){
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }


    void push(int value){
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
    void pop(){
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
    int getFront(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            return arr[front];
        }
    }
    int getSize(){
        if(front == -1 && rear == -1){
            return 0;
        }
        else if(rear < front){
             return size-(front-rear)+1;
        }
        else{
            return abs(front-rear)+1;
        }
    }
    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if(front == 0 && rear == size -1){
            return true;
        }
        else if(front == rear +1){
            return true;
        }
        else{
            return false;
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
    circularqueue cq(5);
    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);
    cq.print();
    cq.push(60);
    cq.pop();
    cq.pop();
    cq.print();
    cq.push(100);
    cq.push(200);
    cq.push(300);
    cq.print();
    cq.pop();
    cq.pop();
    cq.print();
    cout<<cq.getSize()<<endl;
    
return 0;
}