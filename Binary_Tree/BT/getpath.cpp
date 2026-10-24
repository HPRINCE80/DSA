#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x){
        val = x;
        left =  NULL;
        right = NULL;
    }
};
bool getpath(Node* root, vector<int>&arr, int x){
    if(!root) return false;

    arr.push_back(root->val);

    if(root->val==x)  return true;

    if(getpath(root->left,arr,x) || getpath(root->right,arr,x))

    return true;

    arr.pop_back();

    return false;
}

vector<int> solve(Node* root, int B){
    vector<int> arr;
    if(root == NULL)  return arr;

    getpath(root,arr,B);
    return arr;
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

    vector<int> ans = solve(root,5);
    for (int v : ans) 
    cout << v << " ";
    return 0;
}