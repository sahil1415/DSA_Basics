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

int main(){
    // struct stack *s = &s1;
    // s->top = -1;
    // s->size = 5;
    // s->arr = (int*)malloc(sizeof(int)*s->size);
    // printf("Stack created\n");
    // push(s,10);
    // push(s,20);
    // push(s,30);
    // push(s,40);
    // push(s,50);
    // printf("Is stack is full-%d\n",isFull(s));
    // printf("Is stack is empty-%d\n",isEmpty(s));
    // pop(s);
    // printf("Is stack is full-%d\n",isFull(s));
    // printf("Peak element - %d\n",peek(s));
    // pop(s);
    // printf("Peak element - %d\n",peek(s));
    // printf("traversing the stack - \n");
    // traversingStack(s);

    //Alternative method
    struct stack s;
    s.top = -1;
    s.size = 5;
    s.arr = (int*)malloc(sizeof(int)*s.size);
    printf("Stack created\n");
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    push(&s,50);
    printf("Is stack is full-%d\n",isFull(&s));
    printf("Is stack is empty-%d\n",isEmpty(&s));
    pop(&s);
    printf("Is stack is full-%d\n",isFull(&s));
    printf("Top element - %d\n",topp(&s));
    pop(&s);
    printf("Top element - %d\n",topp(&s));
    printf("traversing the stack - \n");
    traversingStack(&s);
}