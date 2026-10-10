#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    private:

    int findMaxGain(TreeNode* root, int& maxSum){
        if(root == nullptr) return 0;
    

    int leftGain = max(0,findMaxGain(root->left, maxSum));
    int rightGain = max(0, findMaxGain(root->right, maxSum));

    int currentPath = root->val + leftGain + rightGain ;
    
    maxSum = max(maxSum , currentPath);

    return root->val + max(leftGain, rightGain);
}
public: 
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;

    findMaxGain(root, maxSum);


    return maxSum;
}
};

    int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;

    cout << solution.maxPathSum(root) << endl;

    return 0;
}