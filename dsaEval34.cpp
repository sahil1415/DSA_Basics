/*Given two integers array pushed and popped each with distinct values, 
return true if this could have been the result of a sequence of push and pop 
operations on an initially empty stack or false otherwise
input: pushed:- [1,2,3,4,5] popped:-[4,5,3,2,1]*/

/*Write a program to calculate the average value of the stack using array elements 
stack elements  = 1,5,3,6,2,0
average = 2.8*/


#include<stdlib.h>
#include<stdio.h>

struct stack{
    int top;
    int *arr;
    int size;
}s1;
int isEmpty(struct stack *s){
    // printf("%d",s->top);
    if(s->top <= -1){
        return 1;
    }
    return 0;
}
int isFull(struct stack *s){
    if(s->top >= s->size-1){
        return 1;
    }
    return 0;
}
void push(struct stack *s,int value){
    if(isFull(s)){
        printf("Stack overflow");
    }
    s->top++;
    s->arr[s->top] = value;
}
void pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    s->top--;
}
int topp(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    return s->arr[s->top];
}
void traversingStack(struct stack *s){
    while(!isEmpty(s)){
      printf("%d\t",s->arr[s->top]);
      pop(s);
    }
    printf("\n");
}
void averageStack(struct stack *s){
    float sum = 0;
    int i = 0;
    while(!isEmpty(s)){
        sum = sum + s-> arr[s->top];
        pop(s);
        i++;
    }
    printf("Average = %f",sum/i);
}

int main(){
    struct stack s;
    s.top = -1;
    s.size = 5;
    s.arr = (int*)malloc(sizeof(int)*s.size);
    printf("Stack created\n");
    push(&s,5);
    push(&s,3);
    push(&s,2);
    push(&s,1);
    push(&s,4);
    // push(&s,0);
    averageStack(&s);
    
}
