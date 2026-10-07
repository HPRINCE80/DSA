#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

bool isTree(TreeNode *q, TreeNode *p)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }
    if (p == nullptr || q == nullptr)
    {
        return false;
    }
    if (p->data != q->data)
    {
        return false;
    }

    return isTree(p->left, q->left) && isTree(p->right, q->right);
}

int main()
{
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
 
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(5);
    q->right = new TreeNode(3);

     cout << (
        isTree(p, q) ? "true" : "false"
    ) << endl;

    return 0;
}