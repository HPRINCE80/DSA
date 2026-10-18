#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = NULL;

    }
};


int heightTree(Node* root, bool& valid){
    
    if(!root)  return 0;
    
    int L = heightTree(root->left, valid);
    int R = heightTree(root->right, valid);
    
    if(abs(L - R) > 1){
        valid = false;
        
        return 1 + max(L, R);
    }
    
    
}
bool isBalacne(Node* root){
    bool valid = true;
    heightTree(root , valid);
    return valid;
}
int mian() {



    return 0;
} 