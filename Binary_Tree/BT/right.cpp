#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void rightview(Node *root, int level, vector<int> &ans)
{
    if (!root)
        return;

    if (level == ans.size())

        ans.push_back(root->data);

    rightview(root->right, level + 1, ans);
    rightview(root->left, level + 1, ans);
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(8);
    vector<int> ans;
    rightview(root, 0, ans);

    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}