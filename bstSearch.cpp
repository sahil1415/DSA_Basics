#include<iostream> 
#include<bits/stdc++.h>
using namespace std;

class Node{

    public:

    int data;
    Node*left;
    Node*right;
  

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};


    Node* insertInBST(Node* &root, int d){
        if(root == NULL){
            Node* root = new Node(d);
            return root;
        }
        if(d < root->data){
            root -> left = insertInBST(root -> left, d);
        }
        else{
            root -> right = insertInBST(root -> right, d);
       }
       return root;
    }
        void takeInput(Node* &root){
        cout<<"Ennter data to insert- ";
        int d;
        cin>>d;
        while(d != -1){
            root = insertInBST(root, d);
            cin>>d;
        }
    }

    bool searchInBST(Node* &root, int x){
        if(root == NULL){
            return false;
        }
        if(root -> data == x){
            return true;
        }
        if(root -> data > x){
            return searchInBST(root -> left, x);
        }
        else{
            return searchInBST(root -> right, x);
        }
    }


    void inOrderTraversal(Node* root){
        if(root == NULL){
            return;
        }
        inOrderTraversal(root -> left);
        cout<<root -> data<<" ";
        inOrderTraversal(root -> right);
    }

int main(){
    Node* root = NULL;
    cout<<"Creating BST"<<endl;
    takeInput(root);
    cout<<"Level order traversal"<<endl;
    inOrderTraversal(root);

   cout<<"Search found : "<<searchInBST(root, 21);
}
