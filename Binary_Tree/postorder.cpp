#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        stack<TreeNode*> s;
        vector<int> ans;

        if (root == nullptr)
            return ans;

        s.push(root);

        while (!s.empty()) {

            TreeNode* temp = s.top();
            s.pop();

            ans.push_back(temp->val);

            // Left first
            if (temp->left)
                s.push(temp->left);
            // Right second
            if (temp->right)
                s.push(temp->right);

        }
        reverse(ans.begin(), ans.end()); // Reverse the result to get postorder

        return ans;
    }
};


int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);


    // Create Solution object
    Solution obj;

    // Call function
    vector<int> ans = obj.postorderTraversal(root);


    // Print answer
    cout << "Postorder Traversal: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}