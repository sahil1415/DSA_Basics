#include<iostream>
using namespace std;

// so basically linkedlist nose is a structure or class which can hold multiple data items
// so the pointer should be also the type of class(name)
class node{
    public:
    int data;
    node* next;

    node(int value){
        this -> data = value;
        this -> next = NULL;
    }
};

// inserting at head
void insertAtHead(int value, node* &head, node* &tail){
    node* newNode  = new node(value);
    // if linkedlist is empty
    if(head == NULL && tail == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        node* temp = head;
        newNode -> next = head;
        head = newNode;
    }
}
void insertAtTail(int value, node* &head, node* &tail){
    node * newNode = new node(value);

    //if empty
    if(head == NULL && tail == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        node * temp = tail;
        // if we use tailnode we dont need to traverse for inserting at end
        // while(temp -> next != NULL){
        //     temp = temp -> next;
        // }
        temp -> next = newNode;

        tail = newNode;
    }
}
int getLength(node* &head){
    node* temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp -> next;
        len++;
    }
    return len;
}
void insertAtPosition(int value, int position, node* &head, node* tail){
    
    if(position == 1){
        insertAtHead(value,head, tail);
    }
    else if(position == getLength(head)+1){
        insertAtTail(value, head, tail);
    }
    else{
        node* newNode = new node(value);
        node* temp1 = head;
        int i=1;
        while(i < position-1){
            temp1 = temp1 -> next;
            i++;
        }
        newNode -> next = temp1->next;
        temp1 -> next = newNode;
    }
}
void traverse(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

bool searchNode(node*head, int value){
    node* temp = head;
    while(temp != NULL){
        if(temp -> data == value){
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

void deleteFromLinkedList(int position, node* &head, node* &tail){
    if(head == NULL && tail == NULL){
        cout<<"LinkedList is Empty"<<endl;
        return;
    }

    if(head == tail){
        node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else{
        if(position == 1){
            node* temp = head;
            head = head -> next;
            delete temp;
        }
        else{
            node* temp = head;
            int i=1; 
            while(i < position-1){
                temp = temp -> next;
                i++;
            }
            temp-> next = temp -> next -> next;
        }
    }

}
int main(){
    node* head = NULL;
    node* tail = NULL;

    insertAtHead(10, head, tail);
    insertAtHead(20, head, tail);
    insertAtHead(30, head, tail);
    insertAtHead(40, head, tail);

    // traverse(head);

    insertAtTail(50, head, tail);
    insertAtTail(60, head, tail);

    // traverse(head);
    // int len = getLength(head);
    // cout<<"Length = "<<len<<endl;

    // insertAtPosition(100, 1,head, tail);
    // insertAtPosition(200, 3,head, tail);
    // insertAtPosition(300, 9,head, tail);
    // traverse(head);

    // cout<<"Searching - "<<searchNode(head, 400);
    traverse(head);
    deleteFromLinkedList(9, head, tail);
    traverse(head);

return 0;
}