#include<stdlib.h>
#include<stdio.h>

struct stack{
    int data;
    struct stack *next;
};
int isEmpty(struct stack *top){
    if(top == NULL){
        return 1;
    }
    return 0;
}

int isFull(struct stack *top){
    struct stack *p = (struct stack*)malloc(sizeof(struct stack));
    if(p == NULL){
        return 1;
    }
    return 0;
}

struct stack* push(struct stack* top, int value){
    if(isFull(top)){
        printf("Stack overflow");
    }
    struct stack* newNode = (struct stack*)malloc(sizeof(struct stack));
    newNode -> data = value;
    // if(top == NULL){
    //     top = newNode;
    //     return;
    // }
    struct stack* temp = top;
    newNode -> next = temp;
    top = newNode;
    return top;
}
void pop(struct stack** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    struct stack* temp = *top;
    *top = (*top) ->next;
    free(temp);
}
int  peek(struct stack* top){
    struct stack* temp = top;
    return temp->data;
}
void stackTraversing(struct stack *top){
    struct stack *temp1 = top;
    while(temp1 != NULL){
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}


int main(){
    struct stack *top = NULL;
    printf("Is stack empty - %d\n",isEmpty(top));
    top = push(top,10);
    top = push(top,20);
    top = push(top,30);
    top = push(top,40);
    printf("Is stack empty - %d\n",isEmpty(top));
    printf("Is stack Full - %d\n",isFull(top));
    printf("PeekElement-%d\n",peek(top));
    pop(&top);
    printf("PeekElement-%d\n",peek(top));
    printf("Traversing the linkedList-\n");
    stackTraversing(top);

















//     //assigining memorry for the nodes
//     head = (struct stack*)malloc(sizeof(struct stack));
//     n2 = (struct stack*)malloc(sizeof(struct stack));
//     n3 = (struct stack*)malloc(sizeof(struct stack));
//     n4 = (struct stack*)malloc(sizeof(struct stack));
//     tail = (struct stack*)malloc(sizeof(struct stack));

//     // assigning values

//     head -> data = 10;
//     n2 -> data = 20;
//     n3 -> data = 30;
//     n4 -> data = 40;
//     tail -> data = 50;

//     //connecting nodes
//     head -> next = n2;
//     n2 -> next = n3;
//     n3 -> next = n4;
//     n4 -> next = tail;
//     tail -> next = NULL;
}