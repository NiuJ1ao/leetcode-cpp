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
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
*/

class Solution {
public:
    // recursive
    // use inorder to determine left subtree and right subtree
    // use postorder to determine the value of current node
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(), postIdx = n - 1;
        return build(inorder, postorder, 0, n-1, postIdx);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l, int r, int& postIdx) {
        if (l > r) return nullptr;
        TreeNode* root = new TreeNode(postorder[postIdx--]);
        int inIdx = l;
        while (inIdx < r && inorder[inIdx] != root->val)
            inIdx++;
        root -> right = build(inorder, postorder, inIdx+1, r, postIdx);
        root -> left  = build(inorder, postorder, l, inIdx-1, postIdx);
        return root;
    }

    // recursive w/ HashMap
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        int n = inorder.size(), postIdx = n - 1;
        return build(inorder, postorder, 0, n-1, postIdx);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l, int r, int& postIdx) {
        if (l > r) return nullptr;
        TreeNode* root = new TreeNode(postorder[postIdx--]);
        int inIdx = mp[root->val];
        root -> right = build(inorder, postorder, inIdx+1, r, postIdx);
        root -> left  = build(inorder, postorder, l, inIdx-1, postIdx);
        return root;
    }
};