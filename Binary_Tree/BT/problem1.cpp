#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

int main()
{
    int x;
    cout << "Enter the Value of Root Node-> ";
    cin >> x;
    int first, second;
    TreeNode *root = new TreeNode(x);
    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        cout << "Enter the Left child " << temp->data << "-> ";
        cin >> first;
        if (first != -1)
        {
            temp->left = new TreeNode(first);
            q.push(temp->left);
        }

        cout << "Enter the right Child" << temp->data << "-> ";
        cin >> second;
        if (second != -1)
        {
            temp->right = new TreeNode(second);
            q.push(temp->right);
        }
    }
    return 0;
}