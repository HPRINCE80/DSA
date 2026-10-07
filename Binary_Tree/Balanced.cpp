#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};


    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        stack<pair<TreeNode *, bool>> nodeStack;
        nodeStack.push(make_pair(root, false));   // FIX: make_pair use kiya

        unordered_map<TreeNode *, int> heightMap;

        while (!nodeStack.empty())
        {
            pair<TreeNode*, bool> top = nodeStack.top();  // FIX: structured binding hataya
            TreeNode* node = top.first;
            bool visited = top.second;
            nodeStack.pop();

            if (!visited)
            {
                nodeStack.push(make_pair(node, true));   // FIX

                if (node->right != nullptr)
                {
                    nodeStack.push(make_pair(node->right, false));  // FIX
                }
                if (node->left != nullptr)
                {
                    nodeStack.push(make_pair(node->left, false));   // FIX
                }
            }
            else
            {
                int leftHeight = node->left ? heightMap[node->left] : 0;
                int rightHeight = node->right ? heightMap[node->right] : 0;

                if (abs(leftHeight - rightHeight) > 1)
                {
                    return false;
                }
                heightMap[node] = 1 + max(leftHeight, rightHeight);
            }
        }
        return true;
    }


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(8);
    root->left->left->left = new TreeNode(8);
    

    
    cout << boolalpha << isBalanced(root) << endl;

    return 0;
}