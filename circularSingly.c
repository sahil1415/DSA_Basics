#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

// function for traversing the linked list

void traversingLinkedList(struct Node *head){
    struct Node * temp = head;
    // while(temp -> next != head){
    //     printf("%d\t", temp -> data);
    //     temp = temp -> next;
    // }
    // printf("%d\t",temp-> data);
    // printf("\n");
    do{
        printf("%d\t",temp -> data);
        temp = temp -> next;
    }
    while(temp != head);
}
int main(){
    // initialising the nodes

    struct Node *head, *n2, *n3, *n4, *tail;

    // creatiing memory for the nodes in heap

    head = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));
    n4 = (struct Node*)malloc(sizeof(struct Node));
    tail = (struct Node*)malloc(sizeof(struct Node));

    // Assigining values to the nodes 

    head -> data = 10;
    n2 -> data = 20;
    n3 -> data = 30;
    n4 -> data = 40;
    tail -> data = 50;

    // connecting the nodes

        head -> next = n2;
        n2 -> next = n3;
        n3 -> next = n4;
        n4 -> next = tail;
        tail -> next = head;

        //traversing the linked list
        traversingLinkedList(head);
}