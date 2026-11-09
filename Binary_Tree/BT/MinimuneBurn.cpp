#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        data = x;
        left =nullptr;
        right = nullptr;
    }
};


int minTime(TreeNode* root, TreeNode* target){
    if(!root || !target)  return 0;

    //Parent Map Banana 
    unordered_map<TreeNode* , TreeNode*> parent;
    queue<TreeNode*> q;

    q.push(root);
    while (!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left){
            parent[curr->left] = curr;
            q.push(curr->left);

        }

        if(curr->right){
            parent[curr->right] = curr;
            q.push(curr->right);

        }
    }
    

    unordered_set<TreeNode* > visited;
    q.push(target);

    visited.insert(target);
    int time = 0;

    while (!q.empty())
    {
        int size = q.size();
        bool burned = false;


        for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->right && !visited.count(curr->right)){
                visited.insert(curr->right);
                q.push(curr->right);
                burned = true;
                
            }
            if(curr->left && !visited.count(curr->left)){
                visited.insert(curr->left);
                q.push(curr->left);
                burned = true;

            }
            if(parent.count(curr) && !visited.count(parent[curr])){
            
                visited.insert(parent[curr]);
                q.push(parent[curr]);
                burned = true;


        }
        
        }
        if(burned)  time++;

    }

    return time;
    


}
int main() 
{   TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left->left;

   cout<<"Minimune Time  -> "<<minTime(root, target)<<" .";
   cout<<"Minimune Time  -> "<<minTime(root, target)<<" .";
   cout<<"Minimune Time  -> "<<minTime(root, target)<<" .";
   cout<<"Minimune Time  -> "<<minTime(root, target)<<" .";

    return 0;
}