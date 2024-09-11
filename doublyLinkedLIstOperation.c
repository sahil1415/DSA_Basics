#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
void insertingElements(struct Node* head, int value){
    
}
// function for traversing the linked list

void traversingLinkedList(struct Node *head){
    struct Node *temp = head;
    while(temp  != NULL){
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

// Inserting at the begening
struct Node* insertAtFirst(struct Node *head, int value){
    struct Node *temp = head;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    head -> prev = newNode;
    newNode -> next = head;
    newNode -> prev = NULL;
    newNode -> data = value;
    return newNode;
}

// Inserting at end
struct Node* insertAtEnd(struct Node *head, int value){
    struct Node *temp = head;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> next = NULL;
    newNode -> prev = temp;
    newNode -> data = value;
    return head;
}

// inserting at any index

struct Node* insertAtIndex(struct Node *head, int index, int value){
    struct Node *temp, *temp1;
    temp = head;
    temp1 = head -> next;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    int i = 0;
    while(i < index-1){
        temp = temp -> next;
        temp1 = temp1 -> next;
        i++;
    }
    temp -> next = newNode;
    newNode -> prev = temp;
    newNode -> next = temp1;
    temp1 -> prev = newNode;
    return head;
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

    printf("Before Insertion \n");
    traversingLinkedList(head);

    // printf("After Insertion \n");
    // struct Node *p = insertAtFirst(head,60);
    // traversingLinkedList(p);

    //  printf("After Insertion \n");
    // struct Node *p = insertAtEnd(head,70);
    // traversingLinkedList(p);

    printf("After Insertion \n");
    struct Node *p = insertAtIndex(head,3,70);
    traversingLinkedList(p);
}