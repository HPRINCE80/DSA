#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
private:
    struct Info {
        int height;
        int distanceFromTarget;
    };

    // Returns subtree height and the distance
    // from the current node to the target.
    Info dfs(
        TreeNode* node,
        TreeNode* target,
        int& maxTime
    ) {
        if (node == nullptr) {
            return {-1, -1};
        }

        Info left =
            dfs(node->left, target, maxTime);

        Info right =
            dfs(node->right, target, maxTime);

        int height =
            1 + max(left.height, right.height);

        // When target is reached, its subtree
        // height gives the farthest downward burn.
        if (node == target) {
            maxTime = max(
                maxTime,
                height
            );

            return {height, 0};
        }

        if (left.distanceFromTarget != -1) {
            int distanceFromTarget =
                left.distanceFromTarget + 1;

            // The route moves from target to this
            // ancestor, then one edge into the
            // opposite subtree and to its deepest node.
            maxTime = max(
                maxTime,
                distanceFromTarget
                + 1
                + right.height
            );

            return {
                height,
                distanceFromTarget
            };
        }

        if (right.distanceFromTarget != -1) {
            int distanceFromTarget =
                right.distanceFromTarget + 1;

            // The left subtree is the opposite
            // branch when target lies on the right.
            maxTime = max(
                maxTime,
                distanceFromTarget
                + 1
                + left.height
            );

            return {
                height,
                distanceFromTarget
            };
        }

        return {height, -1};
    }

public:
    // Finds the maximum distance from target
    // without storing explicit parent links.
    int minTime(
        TreeNode* root,
        TreeNode* target
    ) {
        if (root == nullptr) {
            return 0;
        }

        int maxTime = 0;

        dfs(
            root,
            target,
            maxTime
        );

        return maxTime;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    TreeNode* target = root->left;

    Solution solution;

    cout << solution.minTime(root, target) << endl;

    return 0;
}