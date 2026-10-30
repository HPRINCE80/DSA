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
    // Converts each parent-child connection
    // into an undirected graph edge.
    void buildGraph(
        TreeNode* node,
        unordered_map<TreeNode*, vector<TreeNode*>>& graph
    ) {
        if (node == nullptr) {
            return;
        }

        // Both directions are stored so traversal
        // can move downward as well as upward.
        if (node->left != nullptr) {
            graph[node].push_back(node->left);
            graph[node->left].push_back(node);

            buildGraph(node->left, graph);
        }

        if (node->right != nullptr) {
            graph[node].push_back(node->right);
            graph[node->right].push_back(node);

            buildGraph(node->right, graph);
        }
    }

public:
    // Returns all nodes exactly K edges
    // away from the target node.
    vector<int> distanceK(
        TreeNode* root,
        TreeNode* target,
        int K
    ) {
        vector<int> answer;

        if (root == nullptr) {
            return answer;
        }

        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        buildGraph(root, graph);

        queue<TreeNode*> nodesQueue;
        unordered_set<TreeNode*> visited;

        nodesQueue.push(target);

        // The target is marked immediately so
        // bidirectional edges cannot revisit it.
        visited.insert(target);

        // currLevel represents the number of edges
        // from the target to the current BFS level.
        int currLevel = 0;

        while (!nodesQueue.empty()) {

            // Nodes already in the queue are exactly
            // K edges away, so no further expansion is needed.
            if (currLevel == K) {
                break;
            }

            int levelSize = nodesQueue.size();

            // Exactly one BFS level is processed here.
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                for (TreeNode* neighbor : graph[node]) {
                    if (visited.find(neighbor) == visited.end()) {

                        // Mark before insertion so the same node
                        // cannot enter the queue through another edge.
                        visited.insert(neighbor);
                        nodesQueue.push(neighbor);
                    }
                }
            }

            // Completing one BFS level increases
            // the distance from the target by one.
            currLevel++;
        }

        // Every remaining node is exactly
        // K edges away from the target.
        while (!nodesQueue.empty()) {
            answer.push_back(
                nodesQueue.front()->val
            );
            nodesQueue.pop();
        }

        return answer;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left;
    int K = 2;

    Solution solution;

    vector<int> answer =
        solution.distanceK(root, target, K);

    for (int value : answer) {
        cout << value << " ";
    }

    return 0;
}