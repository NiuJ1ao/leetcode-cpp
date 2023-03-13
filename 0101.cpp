#include <queue>
using namespace std;

/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/

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
    bool isSymmetric(TreeNode* root) {
        return !root || helper(root->left, root->right);
    }

    bool helper(TreeNode* left, TreeNode* right) {
        if (!left || !right) return left == right;
        if (left->val != right->val) return false;
        return helper(left->left, right->right) && helper(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        TreeNode *left, *right;
        while(!q.empty()) {
            left = q.front();
            q.pop();
            right = q.front();
            q.pop();
            if (!left && !right)
                continue;
            if(!left || !right)
                return false;
            if(left->val != right->val)
                return false;
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};