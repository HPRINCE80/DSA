#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


int isSumProperty(Node *root){
    if(root== NULL || (root->left == NULL && root->right == NULL))
    return 1;
 
 
int left_sum = 0, right_sum =0;
if(root->left != NULL) 
left_sum = root->left->data;

if(root->right!= NULL)
right_sum = root->right->data;

if(root->data == (left_sum + right_sum) && isSumProperty(root->left) && isSumProperty(root->right)){
    return true;
}
else{
    return false;
}
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(6);
    root->right = new Node(4);
    // root->right->left = new Node(15);
    // root->right->right = new Node(7);

    
    cout<<boolalpha;
    cout << (isSumProperty(root) ? "True" : "false");

    return 0;
 }