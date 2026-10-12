#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        data = x;
        left = nullptr;
        right = nullptr;

    }
};

void find(TreeNode* root , int pos, int& l, int& r ){
    if(!root){
        return  ;
    }
    l = min(l,pos);
    r = max(r,pos);
    find(root->left, pos-1,l,r);
    find(root->right, pos+1,l,r);
}

vector<int> vecticalOrder(TreeNode* root){
    if (!root) {
    return {};
}
    int l =0, r = 0;
    find(root, 0,l,r);

    vector<vector<int>> positive(r+1);
    vector<vector<int>> negative(abs(l)+1);

    queue<TreeNode* > q;
    queue<int> index;
        q.push(root);
        index.push(0);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            int pos = index.front();
            index.pop();

            if(pos>=0){
                positive[pos].push_back(temp->data);

            }
            else{
                negative[abs(pos)].push_back(temp->data);

            }
        
        if(temp->left) {

            q.push(temp->left);
            index.push(pos-1);
        } 

        if(temp->right){
            q.push(temp->right);
            index.push(pos+1);
        }
    }
        vector<int> ans;

        for(int i = negative.size()-1;i>=1;i--){
            for(int j =0;j<negative[i].size();j++){
                ans.push_back(negative[i][j]);
            }
        }

        for(int i=0;i<(int)positive.size();i++){
            for(int j =0;j<(int)positive[i].size();j++){
                ans.push_back(positive[i][j]);
            }
        }
        return ans;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

vector<int> ans = vecticalOrder(root);
    
        for (int x : ans)
         cout << x << " ";
        
    return 0;
}