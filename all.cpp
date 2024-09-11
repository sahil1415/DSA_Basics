#include<bits/stdc++.h>
using namespace std;

class node{
    int data;
    node* next;

    node(int d){
        this -> data = d;
        this -> next = NULL;
    }
    bool empty(node* &head){
        if(head == NULL){
            return true;
        }
        return false;
    }
};