#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = NULL;
    }
};

// inserting elements inside a linked list

void insertElements(node* &head, int value){
    node* n1 = new node(value);
    if(head == NULL){
        head = n1;
        return;
    }
    node* temp = head;
    while(temp-> next != NULL){
        temp = temp ->next;
    }
    temp -> next = n1;
}
// traversing the linked list

void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    node* head = NULL;
    insertElements(head, 10);
    insertElements(head, 20);
    insertElements(head, 30);
    insertElements(head, 40);
    insertElements(head, 50);

    display(head);
}
