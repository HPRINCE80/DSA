#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr)
    {
    }

};
    
      int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;
        return 1+ max(maxDepth(root->left), maxDepth(root->right));
      }

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);

    cout<<"Maximume Depth Node-> : "<<maxDepth(root)<< endl;
    return 0;
}