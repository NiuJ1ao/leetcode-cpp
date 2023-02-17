#include <algorithm>
using namespace std;

/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

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
    // top-down
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* curr, int hight) {
        if (!curr) return hight;
        return max(dfs(curr->left, hight+1), dfs(curr->right, hight+1));
    }

    // bottom-up
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};