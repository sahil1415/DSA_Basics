#include<iostream>
#include <bits/stdc++.h>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    public:
    node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

/* the tree
        1
       / \
      2   3
     / \   \
    4   5   6

     1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
*/

class binaryTree{
    public:

    node* buildTree() {
    int data;
    cout << "Enter data -> ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }
        node* root = new node(data);
        cout << "Enter left for -> " << data << endl;
        root->left = buildTree();
        cout << "Enter right for -> " << data << endl;
        root->right = buildTree();
        return root;
}

//Iterative traversal of binary tree using stack

     void iterativeInOrder(node* root){
        stack<node*> s;
        node* temp = root;
        while(temp != NULL || !s.empty()){  
            while(temp != NULL){
                s.push(temp);
                temp = temp ->left;
            }
            temp = s.top();
            cout<<temp->data<<" ";
            s.pop();
            temp = temp -> right;
        }
     }

     void iterativePreOrder(node* root){
        stack<node*> s;
        node* temp = root;
        if(root == NULL){
            return;
        }
        s.push(temp);
        while(!s.empty()){
            temp = s.top();
            cout<<temp -> data<<" ";
            s.pop();
            if(temp -> right != NULL){
                s.push(temp -> right);
            }
            if(temp -> left != NULL){
                s.push(temp -> left);
            }
        }

     }

     void iterativePostOrderTraversal(node* root){
        
     }

};

int main(){
    binaryTree bt;
    node* root = bt.buildTree();
    cout<<endl;
    // cout<<"root data="<<root->data;
    cout<<endl<<"Tree Created"<<endl;

    cout<<"IterativeInOrder traversal - "<<endl;
    bt.iterativeInOrder(root);

    cout<<endl<<"Iterative PreOrder Traversal"<<endl;
    bt.iterativePreOrder(root);
}