#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        data = x;
        left= nullptr;
        right = nullptr;
    }
};

void find(TreeNode* root , int pos , int &l){
    if(!root)
    return ;

    l = max(pos, l);

    find(root->left, pos+1, l);
    find(root->right, pos, l);
}


void findDig(TreeNode* root, int pos, vector<vector<int>>& ans){
    if(!root){
        return ;
    }

    ans[pos].push_back(root->data);
    findDig(root->left,pos+1, ans);
    findDig(root->right,pos, ans);
}

vector<int> Digonal(TreeNode* root){

    int l =0;
    find(root, 0, l);
    vector<vector<int>> ans(l+1);
    findDig(root, 0,ans);
    {
        vector<int> temp;


        for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            temp.push_back(ans[i][j]);


        }
        }

        return temp;
    }
}
int main() {

    return 0;
}