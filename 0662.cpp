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
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.
*/

class Solution {
public:
    // BFS
    // Assign an index to each node according to building heap from array.
    int widthOfBinaryTree(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            int cnt = q.size();
            int start = q.front().second;
            int end = q.back().second;

            res = max(res, end - start + 1);
            
            for (int i = 0; i < cnt; i++) {
                pair<TreeNode*, int> curr = q.front();
                q.pop();
                int idx = curr.second - start;
                if (curr.first->left) q.push({curr.first->left, (long long)2*idx+1});
                if (curr.first->right) q.push({curr.first->right, (long long)2*idx+2});
            }
        }

        return res;
    }
};