#include<bits/stdc++.h>
using namespace std;

struct  Node
{
    int data;
    Node * left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void PreOrder(Node* root,vector<int>& res){
    if(root == NULL){
        return ;
    }
    res.push_back(root->data);

    PreOrder(root->left,res);
    PreOrder(root->right,res);

}

void Inorder(Node* root,vector<int>& res){
    if(root == NULL){
        return;
    }
    

    Inorder(root->left,res);

    res.push_back(root->data);

    Inorder(root->right,res);
    
}

void PostOrder(Node* root , vector<int>& res){
    if(root ==NULL){
        return ;
    }

    PostOrder(root->left,res);
    PostOrder(root->right,res);

    res.push_back(root->data);
}


int main(){

     Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> post,in, pre;
    Inorder(root, in);
    PreOrder(root, pre);
    PostOrder(root, post); 


cout << "Inorder:   "; for (int x : in)   cout << x << " "; cout << endl;
cout << "PreOrder:  "; for (int x : pre)  cout << x << " "; cout << endl;
cout << "PostOrder: "; for (int x : post) cout << x << " "; cout << endl;
    return 0;
}