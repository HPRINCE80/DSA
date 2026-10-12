#include<bits/stdc++.h>
using namespace std;
struct  TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
     TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;

     }
    };

vector<vector<int>> zigzag(TreeNode* root){
    vector<vector<int>> result;
    if(root==nullptr) return result;
    queue<TreeNode*> q;

    q.push(root);
     bool lefttoright = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int  i =0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);

            if(node->left)      q.push(node->left);
            if(node->right)     q.push(node->right);

        }

        if(!lefttoright){
            reverse(level.begin() , level.end());
        }

        result.push_back(level);
        lefttoright =! lefttoright;



    }

    return result;


}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> ans = zigzag(root);
    for (auto& level : ans) {
        for (int x : level) cout << x << " ";
        cout << "\n";
    }
    return 0;
}