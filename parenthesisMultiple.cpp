#include<iostream>
using namespace std;

class stack{
    char data;
    stack* next;


    public:
    stack* top;
    stack(){
        top = NULL;
    }
    stack(char value){
        data  = value;
        next = NULL;
    }

    bool empty(){
        return top==NULL;
    }
    void push(int value){
        stack* newNode = new stack(value);
        stack* temp = top;
        newNode -> next = temp;
        top = newNode;
    }

    char pop(){
        if(empty()){
            return '\0';
        }
        stack* temp1 = top;
        char c = temp1 -> data;
        top = top-> next;
        delete temp1;
        return c;
    }
    char Top(){
        return top->data;
    }
    bool matching(char ch1, char ch2){
        if(ch1 == '(' && ch2 == ')' || ch1 == '{' && ch2 == '}' || ch1 == '[' && ch2 == ']'){
            return true;
        }
        return false;
    }

    bool parenthesisChecking(string str){
        int i = 0;
        while(str[i] != '\0'){
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                push(str[i]);
            }
            else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
                if(empty()){
                    return false;
                }
                char ch = pop();
                if(!matching(ch,str[i])){
                    return false;
                }
            }
            i++;
        }
        if(empty()){
            return true;
        }
        return false;
    }
};

int main(){
    stack s;
    string st = "{[{(5*6)}]}";
    if(s.parenthesisChecking(st)){
        cout<<"Balanced Expression";
    }
    else{
        cout<<"Unbalanced Expression";
    }
}