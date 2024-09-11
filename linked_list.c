
#include<stdlib.h>
#include<stdio.h>

int main(){
    struct node{
        int data;
        struct node *next;
    };
    // Initializing nodes
    struct node *head;
    struct node *n1;
    struct node *n2;
    struct node *n3;

    // Allocating memories
    n1 = (struct node*)malloc(sizeof(struct node));
    n2 = (struct node*)malloc(sizeof(struct node));
    n3 = (struct node*)malloc(sizeof(struct node));

    // Assigning data values
    n1 -> data = 10;
    n2 -> data = 20;
    n3 -> data = 30;

    // Connecting nodes 
    head = n1;
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = NULL;

    // Traversing the linked list
    struct node *temp = head;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}