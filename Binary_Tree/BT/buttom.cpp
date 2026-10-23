#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void solve(Node* root,int line, int depth, map<int , pair<int,int>>& mp){
    // root is empty
    if(root==NULL) return;
    
    // push element in the map
    if(mp.find(line) == mp.end() || depth >= mp[line].first){
        mp[line] = {depth , root->data};
    }

    solve(root->left,line -1,depth + 1,mp);
    solve(root->right,line +1,depth + 1,mp);

}

vector<int> Buttomview(Node* root){
    vector<int> ans;
    map<int , pair<int, int>> mp;
    solve(root, 0,0,mp);


    for(auto it : mp){
        ans.push_back(it.second.second);
    }

    return ans;
}
int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

    vector<int> ans = Buttomview(root);
    for(int x : ans){
        cout<< x<<" ";
    }

    return 0;
}