#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // For a complete binary tree, there should not be any node after we met an empty one.
    // BFS
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> bfs;
        bfs.push_back(root);
        int i = 0;
        while (i < bfs.size() && bfs[i]) {
            bfs.push_back(bfs[i]->left);
            bfs.push_back(bfs[i]->right);
            i++;
        }
        while (i < bfs.size() && !bfs[i]) {
            i++;
        }
        return i == bfs.size();
    }

    // DFS
    // If a tree is complete and full, x (num of nodes) = 2^k - 1, x has a property that x & (x+1) == 0.
    // For a complete tree, it must satisfy one of the following condition:
    //  1. if left subtree is full with l nodes, right subtree must have r nodes that l/2 <= r <= l
    //  2. if right subtree is full with r nodes, left subtree must have l nodes that r <= l <= r * 2 + 1
    bool isCompleteTree(TreeNode* root) {
        return dfs(root) > 0;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if ((l & (l + 1)) == 0 && l/2 <= r && r <= l) {
            return l + r + 1;
        }
        if ((r & (r + 1)) == 0 && r <= l && l <= r * 2 + 1) {
            return l + r + 1;
        }
        return -1;
    }
};