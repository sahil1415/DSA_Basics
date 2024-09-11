#include<iostream>
using namespace std;
class deque{
    public:
    int size;
    int front;
    int rear;
    int* arr;

    deque(int size){
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    void push_back(int value){
        // if queue is full
        if(rear == size - 1){
            cout<<"Dequeue Overflow"<<endl;
        }

        // if empty
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = value;
        }
        else{
            arr[++rear] = value;
        }
    }
    void push_front(int value){
        if(front == 0){
            cout<<"Queue Overflow"<<endl;
        }

        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front] = value;
        }
        else{
            front--;
            arr[front] = value;
        }
    }

    void pop_back(){
        if(front == -1 && rear == -1){
            cout<<"Queue UnderFlow"<<endl;
        }

        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;

        }
        else{
            arr[rear] = -1;
            rear--;
        }
    }
    void pop_front(){
        if(front == -1 && rear == -1){
            cout<<"Queue underFlow"<<endl;
        }

        // single element
        if(front == rear){
            arr[front = -1];
            front = -1;
            rear = -1;
        }
        else{
            arr[front] = -1;
            front--;
        }
    }
    void print(int size){
        for (int i=0; i<size; i++){
            cout<<arr[i]<<"  ";
        }
    }
};
int main()
{
    deque dq(5);
    dq.push_front(1);
    dq.push_back(2);
    // dq.push_front(3);
    dq.push_back(4);
    // dq.push_front(5);

    dq.print(5);

return 0;
}