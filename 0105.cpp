#include <vector>
#include <unordered_map>
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
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
*/

class Solution {
public:
    // use preorder to determine the value, use inorder to determine left or right subtree.
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(), preIdx = 0;
        return build(preorder, inorder, 0, n-1, preIdx);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r, int& preIdx) {
        if (l > r) return nullptr;
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        int inIdx = l;
        while (inIdx < r && inorder[inIdx] != root -> val) {
            inIdx++;
        }
        root -> left = build(preorder, inorder, l, inIdx-1, preIdx);
        root -> right = build(preorder, inorder, inIdx+1, r, preIdx);
        return root;
    }

    // optimized index search with map
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(), preIdx = 0;
        unordered_map<int, int> inorderIdxMap;
        for (int i = 0; i < n; i++)
            inorderIdxMap[inorder[i]] = i;
        return build(preorder, inorderIdxMap, 0, n-1, preIdx);
    }

    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorderIdxMap, int l, int r, int& preIdx) {
        if (l > r) return nullptr;
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        int inIdx = inorderIdxMap[root->val];
        root -> left = build(preorder, inorderIdxMap, l, inIdx-1, preIdx);
        root -> right = build(preorder, inorderIdxMap, inIdx+1, r, preIdx);
        return root;
    }
};