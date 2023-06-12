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

/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0, r = nums.size();
        return helper(nums, l, r);
    }

    TreeNode* helper(vector<int>& nums, int l, int r) {
        if (l >= r) return nullptr;
        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = helper(nums, l, m);
        root->right = helper(nums, m + 1, r);
        return root;
    }
};