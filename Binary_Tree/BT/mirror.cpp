#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;

    }
};

void Mirror(Node* root) {

    if(root==NULL)  return ;
    Node* temp = root->right;
    root->right = root->left;
    root->left = temp;

    Mirror(root->left);
    Mirror(root->right);
}


void inorder(Node* root){
    if(!root) return;

    cout<<root->data<<" ";
    
    inorder(root->left);
    inorder(root->right);
}
int main() {

     Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6); 
    root->right->right->left = new Node(9); 
    root->right->right->right = new Node(8);
      
    
    Mirror(root);
    inorder(root);
    
    return 0;

}