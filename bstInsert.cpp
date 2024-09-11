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

    void levelOrderTraversal(Node* root){

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* temp = q.front();
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

                if(temp -> left){
                q.push(temp -> left);
               }
                if(temp -> right){
                q.push(temp -> right);
                }
            }
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
    levelOrderTraversal(root);
}
