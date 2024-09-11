#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};

// traversing the Linked List

void traversingList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp -> next;
    }
    printf("\n");
}
// deleting the first element of the linked list
struct Node* deletingFirst(struct Node *head){
    struct Node *temp = head;
    head = head -> next;
    free (temp);

    return head;

}
int main(){
    // initialising the nodes
    struct Node *head, *n2, *n3, *n4, *tail;
    
    //allocating the memories for nodes

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

    // linking the nodes all together

    head -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = tail;
    tail -> next = NULL;

    // traversing the linked list
    traversingList(head);

    printf("Traversing after deleting the first node-\n");
    struct Node *p = deletingFirst(head);
    traversingList(p);
}