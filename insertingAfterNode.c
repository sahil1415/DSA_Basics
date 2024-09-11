#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

void traversingLinkedList(struct Node * head){
    struct Node *temp;
    temp = head;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp -> next;
    }
    printf("\n");
}

// Inserting after any node by passing pointer as an argument for the point of the insertion
struct Node* insertionAfterNode(struct Node *ptr, struct Node * h, int value){
    struct Node *temp = h;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode ->next = ptr -> next;
    ptr->next = newNode;

    return h;
}
int main(){
    // initailising the nodes
    struct Node *head , *n2, *n3, *n4, *tail;

    // creating memory in heap for the nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));
    n4 = (struct Node*)malloc(sizeof(struct Node));
    tail = (struct Node*)malloc(sizeof(struct Node));

    // assigining values to the nodes

    head -> data = 10;
    n2 -> data = 20;
    n3 -> data = 30;
    n4 -> data = 40;
    tail -> data = 50;

    // connecting the nodes all together

    head -> next = n2;
    n2 -> next = n3;
    n3 -> next  =n4;
    n4 -> next = tail;
    tail -> next = NULL;

    //traversing the nodes
    traversingLinkedList(head);

    // Inserting after a node
    struct Node *p = insertionAfterNode(n2,head,80);

    printf("After inserting a node -\n");
    traversingLinkedList(p);
}