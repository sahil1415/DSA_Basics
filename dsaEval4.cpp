#include<iostream>
using namespace std;

class queue{
    int data;
    int first;
    int last;
    int *arr;
    int maxsize;

    public:
    queue(int size){
        maxsize = size;
        first = -1;
        last = -1;
        arr = new int(sizeof(int)*maxsize);
    }
    bool isFull(){
        if(last == maxsize-1){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(last == first){
            return true;
        }
        return false;
    }
    void enqueue(int value){
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
        }
        last += 1;
        arr[last] = value;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue UnderFlow"<<endl;
        }
            first += 1;
            return arr[first];
    }
    int front(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
        }
        return arr[++first];
    }
    int rear(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
        }
        return arr[last];
    }
    void averageQueue(){
        int sum = 0;
        while(first>last){
            sum = sum + arr[first];
            first++;
        }
        cout<<"Sum = "<<sum;
    }
};

int main(){
    queue q(6);
    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(6);
    q.enqueue(2);
    q.enqueue(0);
    q.averageQueue();


}