#include<iostream>
using namespace std;

class circularQueue{
    int maxsize;
    int first;
    int last;
    int * arr;

    public:
    circularQueue(int size){
        first = -1;
        last = -1;
        maxsize = size;
        arr = new int(sizeof(int)*maxsize);
    }

    bool isEmpty(){
        if(last == -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if((last+1) % maxsize-1 == first ){
            return  true;
        }
        else if(last == maxsize-1 && first == -1){
            return true;
        }
        return false;
    }

    void enQueue(int value){
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
        }
        last = (last+1) % maxsize-1;
        arr[last] = value;
    }

    int deQueue(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
        }
        int result = arr[first+1];
        if(first = last){
            first = last = -1;
        }
        else{
            first = (first+1) % maxsize-1;
        }
        return result;
    }
};

int main(){
    circularQueue cq(5);
    cout<<"Is th queue empty - "<<cq.isEmpty()<<endl;
    cout<<"Is the queue full - "<<cq.isFull()<<endl;

    cq.enQueue(10);
    cq.enQueue(20);

    cout<<"Is th queue empty - "<<cq.isEmpty()<<endl;
    cout<<"Is the queue full - "<<cq.isFull()<<endl;

    cq.enQueue(30);
    cq.enQueue(40);
    cq.enQueue(50);

    cout<<"Is the queue full - "<<cq.isFull()<<endl;

    cout<<"Element dequeued - "<<cq.deQueue()<<endl;
    cout<<"Element dequeued - "<<cq.deQueue()<<endl;

    cout<<"Is th queue empty - "<<cq.isEmpty()<<endl;
    cout<<"Is the queue full - "<<cq.isFull()<<endl;

}