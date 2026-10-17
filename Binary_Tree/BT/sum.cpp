#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = NULL;

    }

    
};

int SumOfBT(Node* root){
    if(root==NULL)  return 0;
    
    return root->data + SumOfBT(root->left) + SumOfBT(root->right); 
}
int main() {
     Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6); 

    cout<<"Sum of given Binary Tree -> : "<<SumOfBT(root);

    return 0;
}