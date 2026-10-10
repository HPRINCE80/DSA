#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
class Solution {
public:
   
         int ans =0;
         int height(TreeNode* root){
        if(root ==NULL)  return 0;
        int leftHt = height(root->left);
        int rightHt = height(root->right);
        
        ans = max(ans, leftHt+ rightHt);
        return max(leftHt, rightHt) + 1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return ans;
    }
        
    
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
 
    Solution solution;
 
    cout << solution.diameterOfBinaryTree(root)
         << endl;
 
    return 0;
    
}