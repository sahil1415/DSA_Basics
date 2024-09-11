#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    //creating  node
    node(int value){
        data = value;
        next = NULL;
    }
};

//inserting a element inside a linked list

void creatingAlinkedList(int value, node *&head){   // so int *a is call by value
    // allocating memory for the node               // and int *&a is passed by reference
    // node *n1;
    // n1 = new node(value);
    node *n1 = new node(value);
    // means the linked list has no nodes yet
    if(head == NULL){
        head = n1;
        return;
    }
    else{
         node *temp = head;
        while(temp->next !=NULL){
            temp = temp -> next;
        }
        temp -> next = n1;
        n1 -> next = NULL;
    }
}
void displayList(node *&head){
    node * temp  = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
}

node *insertingAtFront(node *head, int value){
    node * temp = head;
    node *firstNode = new node(value);
    firstNode -> next = temp;
    return firstNode;
}

node *insertingAtEnd(node *head, int value){
    node * temp = head;
    node *lastNode = new node(value);
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = lastNode;
    return head;
}
node *insertingAtIndex(node *head, int value, int index){
    node *temp = head;
    node *temp1 = head->next;
    node *midNode = new node(value);
    int i= 0;
    while(i<index-1){
        temp = temp -> next;
        temp1 = temp1 -> next;
        i++;
    }
    temp -> next = midNode;
    midNode -> next = temp1;
    return head;
}

int main(){
    node *head = NULL;
    creatingAlinkedList(10,head);
    creatingAlinkedList(20,head);
    creatingAlinkedList(30,head);
    creatingAlinkedList(40,head);
    creatingAlinkedList(50,head);
    displayList(head);
    cout<<"\n\nAfter Insertion at front\n";
    // insert at the front
    node *n1 = insertingAtFront(head, 60);
    cout<<"first";
    displayList(n1);

    cout<<"\n\nAfter Insertion at End\n";
    node *n2 = insertingAtEnd(n1, 70);
    displayList(n2);
    cout<<"end";

    cout<<"\n\nAfter Insertion at Mid\n";
    node *n3 = insertingAtIndex(n2, 80, 3);
    displayList(n3);
}





// #include<iostream>
// using namespace std;

// class node{
//     public:
//     int data;
//     node* next;

//     // Creating a node `
//     node(int value){
//         data = value;
//         next = NULL;
//     }
// };

// // inserting elements inside a linked list

// void insertElements(node* &head, int value){
//     node* n1 = new node(value);   // allocating memory of the new node 
//     if(head == NULL){
//         head = n1;
//         return;
//     }
//     node* temp = head;
//     while(temp-> next != NULL){
//         temp = temp ->next;
//     }
//     temp -> next = n1;
//     n1 -> next = NULL;
// }
// // traversing the linked list

// void display(node* &head){
//     node* temp = head;
//     while(temp != NULL){
//         cout<<temp -> data <<" ";
//         temp = temp -> next;
//     }
//     cout<<endl;
// }

// int main(){
//     node* head = NULL;
//     insertElements(head, 10);
//     insertElements(head, 20);
//     insertElements(head, 30);
//     insertElements(head, 40);
//     insertElements(head, 50);

//     display(head);
// }
