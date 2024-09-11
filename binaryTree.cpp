#include<iostream>
#include <bits/stdc++.h>
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


    void levelOrderTraversal(node* root){

        queue<node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            node* temp = q.front();
            q.pop();

            if(temp == NULL){
                // purana level complete
                cout<<endl;
                if(q.empty()){
                    // queue has some child nodes
                    q.push(NULL);
                }
            }
            else{
               cout<< temp -> data <<" ";

                if(temp -> left != NULL){
                q.push(temp -> left);
               }
                if(temp -> right != NULL){
                q.push(temp -> right);
                }
            }
        }
    }

    void inOrderTraversal(node* root){
        if(root == NULL){
            return;
        }
        inOrderTraversal(root -> left);
        cout<<root -> data<<" ";
        inOrderTraversal(root -> right);
    }

    void preOrderTraversal(node* root){
        if(root == NULL){
            return;
        }
        cout<<root -> data<<" ";
        preOrderTraversal(root -> left);
        preOrderTraversal(root -> right);
    }

      void postOrderTraversal(node* root){
        if(root == NULL){
            return;
        }
        postOrderTraversal(root -> left);
        postOrderTraversal(root -> right);
        cout<<root -> data<<" ";
    }
};

int main(){
    binaryTree bt;
    node* root = bt.buildTree();
    cout<<endl;
    // cout<<"root data="<<root->data;
    cout<<endl<<"Tree Created"<<endl;

    cout<<"Level Order Traversal - "<<endl;
    bt.levelOrderTraversal(root);

    cout<<endl<<"Inorder Traversal"<<endl;
    bt.inOrderTraversal(root);

    cout<<endl<<"Preorder Traversal"<<endl;
    bt.preOrderTraversal(root);

    cout<<endl<<"Postorder Traversal"<<endl;
    bt.postOrderTraversal(root);

    
}