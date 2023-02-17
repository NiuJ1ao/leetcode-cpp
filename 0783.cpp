#include <algorithm>
#include <climits>
using namespace std;

/*
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
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
    int minDiffInBST(TreeNode* root) {
        int prev = -1;
        int res = INT_MAX;
        inOrderTraversal(root, &res, nullptr);
        return res;
    }

    void inOrderTraversal(TreeNode* curr, int* diff, int* prev) {
        if (!curr) return;
        inOrderTraversal(curr->left, diff, prev);
        if (*prev > -1)
            *diff = min(*diff, curr -> val - *prev);
        *prev = curr -> val;
        inOrderTraversal(curr->right, diff, prev);
        return;
    }
};