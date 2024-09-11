#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int value){
        data = value;
        prev = NULL;
        next = NULL;
    }
};
    void insertAtHead(int value, node* &head, node* &tail){
        node* newNode = new node(value);
        if(head == NULL && tail == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }
    void insertAtTail(int value, node* &head, node* &tail){
        node* newNode = new node(value);
        if(head == NULL && tail == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            // node* temp = head;
            // while(temp -> next != NULL){
            //     temp = temp -> next;
            // }
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }
    int getLength(node* &head){
        node* temp = head;
        int len = 1;
        while(temp -> next != NULL){
            len++;
            temp = temp -> next;
        }
        return len;
    }
    void insertAtPosition(int position, int value, node* &head, node* &tail){
        node* newNode = new node(value);
        if(position == 1){
            insertAtHead(value, head, tail);
        }
        else if(position == getLength(head)-1){
            insertAtTail(value, head, tail);
        }
        else{
            node* temp1 = head;
            node* temp2 = head;
            int i = 1;
            while(i < position-1){
                temp1 = temp1 -> next;
                temp2 = temp1 -> next;
                i++;
            }
            temp1 -> next = newNode;
            newNode -> prev = temp1;

            newNode -> next = temp2;
            temp2 -> prev = newNode;
        }
    }
    bool searching(int target, node* head){
        node* temp = head;
        while(temp != NULL){
            if(temp -> data == target){
                return true;
            }
            temp = temp -> next;
        }
        return false;
    }
    void deleteFromLinkedlist(int position, node* &head, node* &tail){
        if(position < 1 || position > getLength(head)){
            cout<<"Position out of bound"<<endl;
            return;
        }
        if(head == NULL && tail == NULL){
            cout<<"Linkedlist is Empty"<<endl;
            return;
        }
        else if(head == tail){
            // single node
            node*temp = head;
            head = NULL;
            tail = NULL;
            
            delete temp; 
        }

        else if(position == 1){
            node* temp = head;
            head = head -> next;
            head -> prev = NULL;
            temp -> next = NULL;
            delete temp;
        }
        else if(position == getLength(head)){
            node* temp = tail;
            tail = tail -> prev;
            tail -> next = NULL;
            temp -> prev = NULL;
            delete temp;
        }
        else{
            node* left = head;
            int i=1;
            while(i < position-1){ // we are at the node to delete
                left = left -> next;
                i++;
            }
            node* current = left -> next;
            node* right = current -> next;
            left -> next = right;
            right -> prev = left;
            current -> next = NULL;
            current -> prev = NULL;
            delete current;

        }
    }
    void traversee(node* &head){
        node* temp = head;
        while(temp != NULL){
            cout<<temp -> data<<" -> ";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }
int main()
{
    node* head = NULL;
    node* tail = NULL;
    insertAtHead(10, head, tail);
    insertAtHead(20, head, tail);
    insertAtHead(30, head, tail);
    insertAtTail(40, head, tail);
    insertAtTail(50, head, tail);
    // insertAtPosition(3,100, head, tail);
    // traversee(head); 
    // cout<<searching(10, head);

    deleteFromLinkedlist(1, head, tail);
    traversee(head);
    // cout<<getLength(head)<<endl;
    deleteFromLinkedlist(5, head, tail);
    traversee(head); 
    deleteFromLinkedlist(10, head, tail);
    traversee(head);
return 0;
}