#include <queue>
using namespace std;

/*
Given the root of a binary tree, invert the tree, and return its root.
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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) continue;

            // swap left and right
            TreeNode* tmp = node -> left;
            node -> left = node -> right;
            node -> right = tmp;
            
            q.push(node->left);
            q.push(node->right);
        }
        return root;
    }
};