#include <tuple>
#include <queue>
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
You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.
*/

class Solution {
public:
    // BFS
    typedef tuple<TreeNode*, bool, int> myTuple;
    int longestZigZag(TreeNode* root) {
        int res = 0;

        queue<myTuple> q;
        if (root->left) q.push(make_tuple(root->left, true, 1)); // left
        if (root->right) q.push(make_tuple(root->right, false, 1)); // right
        while (!q.empty()) {
            myTuple curr = q.front();
            q.pop();
            
            TreeNode* node = get<0>(curr);
            bool isLeft = get<1>(curr);
            int currLen = get<2>(curr);
            res = max(res, currLen);

            if (isLeft) {
                if (node->right) q.push(make_tuple(node->right, !isLeft, currLen + 1));
                if (node->left) q.push(make_tuple(node->left, isLeft, 1));
            } else {
                if (node->left) q.push(make_tuple(node->left, !isLeft, currLen + 1));
                if (node->right) q.push(make_tuple(node->right, isLeft, 1));
            }
        }

        return res;
    }

    // DFS
    int longestZigZag(TreeNode* root) {
        int ans=0;
        ziggy(root, 0, 0, ans);
        return ans;
    }

    void ziggy(TreeNode* root, int l, int r, int& ans){
        if (!root) return;
        ans = max(ans, l);
        ans = max(ans, r);
        ziggy(root->left, 0, l+1, ans);
        ziggy(root->right, r+1, 0, ans);
        return;
    }
};