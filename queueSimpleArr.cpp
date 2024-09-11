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
        if(isEmpty()){
            first +=1;
        }
        last += 1;
        arr[last] = value;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue UnderFlow"<<endl;
        }
            return arr[first];
            first += 1;
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
};

int main(){
    queue q(5);
    cout<<"Is queue empty - "<<q.isEmpty()<<endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<"Is queue full - "<<q.isFull()<<endl;
    cout<<"Dequed element = "<<q.dequeue()<<endl;
    cout<<"Dequed element = "<<q.dequeue()<<endl;
    cout<<"Dequed element = "<<q.dequeue()<<endl;
    cout<<"Dequed element = "<<q.dequeue()<<endl;
    cout<<"Dequed element = "<<q.dequeue()<<endl;
    cout<<"Is queue empty - "<<q.isEmpty()<<endl;
    cout<<"Is queue full - "<<q.isFull()<<endl;
    cout<<"Front element - "<<q.front()<<endl;
    cout<<"Rear element - "<<q.rear()<<endl;
}