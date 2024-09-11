#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
// function for traversing the linked list

void traversingLinkedList(struct Node *head){
    struct Node *temp = head;
    while(temp  != NULL){
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
int main(){
    // initialising the nodes

    struct Node *head, *n2, *n3, *n4, *tail;

    // creating memory in heap for the nodes

    head = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));
    n4 = (struct Node*)malloc(sizeof(struct Node));
    tail = (struct Node*)malloc(sizeof(struct Node));

    // assing data values

    head -> data = 10;
    n2 -> data = 20;
    n3 -> data = 30;
    n4 -> data = 40;
    tail -> data = 50;

    // connecting the next nodes nodes;

    head -> next  = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = tail;
    tail -> next = NULL;

    // connecting the previous nodes

    head -> prev = NULL;
    n2 -> prev = head;
    n3 -> prev = n2;
    n4 -> prev = n3;
    tail -> prev = n4;

    // calling the traversing function

    traversingLinkedList(head);
}