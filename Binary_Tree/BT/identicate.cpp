#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


bool identical(Node* root1, Node* root2){

    if( root1==NULL && root2 == NULL) return 1;

    if((!root1 && root2 )|| (root1 && !root2))  return 0;

    if(root1->data != root2->data) return 0;

    return identical(root1->left, root2->left)  && identical(root1->right, root2->right);

}
int main() {
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->right = new Node(6); 
    root1->right->right->left = new Node(9); 
    root1->right->right->right = new Node(8);


     Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->right = new Node(6); 
    root2->right->right->left = new Node(9); 
    root2->right->right->right = new Node(8);

    cout<<boolalpha;
    cout<<identical(root1, root2);

    return 0;
}