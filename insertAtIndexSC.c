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
    printf("\n");
}
// Function to insert Linked List at the begining of List
struct Node* insertAtIndex(struct Node * head, int value, int index){
    struct Node *newNode, *temp, *temp1;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    temp1 = head -> next;
    newNode -> data = value;
    int i = 0;
    while(i < index-1){
        temp = temp -> next;
        temp1 = temp1 -> next;
        i++;
    }
    temp -> next = newNode;
    newNode -> next = temp1;
    return head;
    // do{
    //     temp = temp -> next;
    // }
    // while(temp != head);
    // temp -> next = newNode;
    // newNode -> next = head;
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
        printf("Linked List before - \n");
        traversingLinkedList(head);

        struct Node *p = insertAtIndex(head, 60, 2);
        printf("Linked LIst after inserting at the begening of the linked list- \n");
        traversingLinkedList(p);
}