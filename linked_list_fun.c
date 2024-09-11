#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct node *next;
};

void traversingLinkedList(struct Node* h){
    struct Node *temp = h;
    while(temp != NULL){
        printf("%d\t",temp -> data);
        temp = temp ->next;
    }
    printf("\n");
}
// Inserting at the begening
struct Node* insertAtFirst(struct Node* h, int value){
    struct Node *First;
    First = (struct Node*)malloc(sizeof(struct Node));
    First -> data = value;
    First -> next = h;

    return First;
}

// Inserting in the middle at a given index
struct Node* insertAtIndex(struct Node* h, int index, int value){
    struct Node *temp = h;
    struct Node *Ni = (struct Node*)malloc(sizeof(struct Node));
    int i = 0;
    while(i<index){
        temp = temp -> next;
        i++;
    }
    Ni -> data = value;
    temp -> next = Ni;
    Ni -> next = temp;

    return h;
}

int main(){  
     // initializing nodes
    struct Node *Head;
    struct Node *N2;
    struct Node *N3;
    struct Node *N4;

    // creating memeory in heap for nodes
    Head = (struct Node*)malloc(sizeof(struct Node));
    N2 = (struct Node*)malloc(sizeof(struct Node));
    N3 = (struct Node*)malloc(sizeof(struct Node));
    N4 = (struct Node*)malloc(sizeof(struct Node));

    //assigning nodes values

    Head -> data = 10;
    N2 -> data = 20;
    N3 -> data = 30;
    N4 -> data = 40;

    // connecting nodes

    Head -> next  = N2;
    N2 -> next = N3;
    N3 -> next = N4;
    N4 -> next = NULL;

    traversingLinkedList(Head);

    //Inserting a node at first

    struct Node *ptr = insertAtFirst(Head,50);

    printf("After inserting the node-\n");

    traversingLinkedList(ptr);

    printf("Inserting at a particular index -\n");

    Head = insertingAtIndex(Head,2,50);
    traversingLinkedList(Head);
}









