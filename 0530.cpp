#include <climits>
#include <algorithm>
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

/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
*/

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX, prev = -1;
        inOrderTraversal(root, diff, prev);
        return diff;
    }

    void inOrderTraversal(TreeNode* root, int& diff, int& prev) {
        if (!root) return;
        inOrderTraversal(root->left, diff, prev);
        if (prev > -1)
            diff = min(diff, abs(root->val - prev));
        prev = root->val;
        inOrderTraversal(root->right, diff, prev);
    }
};