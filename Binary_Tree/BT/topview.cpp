#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x){
        val = x;
        left = right = NULL;

    }

};

void find(Node* root, int pos ,int& l , int& r){
    if(!root) return;

    l = min(pos,l);
    r = max(pos, r);

    find(root->left,pos-1,l,r);
    find(root->right,pos+1,l,r);


}


vector<int> topview(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;

    map<int, int> map;
    queue<pair<Node*, int>>q;
    q.push({root,0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        if(map.find(line)  == map.end())  map[line] = node->val;



        if(node->left != NULL)  q.push({node->left,line-1});

        if(node->right !=NULL)  q.push({node->right,line+1});

    }
    for(auto it: map){
        ans.push_back(it.second);
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

    vector<int> ans = topview(root);

    for(int x : ans){
        cout<<x<<" ";
    }    return 0;
}