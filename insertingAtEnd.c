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

struct Node* insertAtEnd(struct Node* h, int value){
    struct Node * End;
    End = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = h;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp -> next  = End;
    End -> data = value;
    End ->next = NULL;
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

     printf("Inserting at End -\n");
     struct Node *ptr;

    ptr = insertAtEnd(Head,60);
    traversingLinkedList(ptr);

}