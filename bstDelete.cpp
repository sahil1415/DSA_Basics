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
    int minVal(Node* root){
        Node* temp = root;
        while(temp -> left != NULL){
            temp = temp -> left;
        }
        return temp -> data;
    }

    Node* deletefromBST(Node* root, int x){
        if(root == NULL) return root;

        
        if(root -> data == x){
            // 0 child
            if(root -> left == NULL && root -> right == NULL){
                delete root;
                return NULL;
            }
            // 1 left child
            if(root -> left != NULL && root -> right == NULL){
                Node* temp = root -> left;
                delete root;
                return temp;
            }
            // 1 right child
            if(root -> right != NULL && root -> left == NULL){
                Node*temp = root -> right;
                delete root;
                return temp;
            }

            // if have a sub tree
            if(root -> left != NULL && root -> right != NULL){
                int mini = minVal(root -> right);
                root -> data = mini;
                root -> right = deletefromBST(root -> right, mini);
                return root;
            }

        }
        else if(root -> data > x){
            root ->left = deletefromBST(root -> left, x);
            return root;
        }
        else{
            root -> right = deletefromBST(root -> right, x);
            return root;
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

//    cout<<"Search found : "<<searchInBST(root, 21);
     deletefromBST(root, 5);
     cout<<endl;
     inOrderTraversal(root);
}
