#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int x){
        data = x;
        left = right = NULL;

    }
};

void countLeave(Node* root, int& count){
    if(root==NULL) return;

    if(!root->left && !root->right){
        count++;
        return;
    }
    
    countLeave(root->left,count);
    countLeave(root->right,count);
}

int countLeaveall(Node* root){
    if(root==NULL)  return 0;
    
    if(!root->left && !root->right)  return 1;
        return countLeaveall(root->left) + countLeaveall(root->right);
    
}

int main() {

  Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6); 
  int count = 0;
  countLeave(root,count);
    cout<<"Count All Leave "<<count;
    cout<<endl;
    cout<<"Count All Leave "<<countLeaveall(root);

    return 0;
}