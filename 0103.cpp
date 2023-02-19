#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
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
    // BFS + reverse
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            pair<TreeNode*, int> curr = q.front();
            TreeNode* node = curr.first;
            int lvl = curr.second;
            q.pop();

            if (node) {
                if (lvl >= res.size()) {
                    res.push_back(vector<int>{node -> val});
                } else {
                    res[lvl].push_back(node -> val);
                }

                int nLvl = lvl + 1;
                q.push(make_pair(node -> left, nLvl));
                q.push(make_pair(node -> right, nLvl));
            }
        }

        // reverse odd rows
        for (int i = 0; i < res.size(); i++) {
            if (i % 2 != 0) {
                reverse(res[i].begin(), res[i].end());
            }
        }
        return res;
    }

    // BFS without reverse operations
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // find position to fill node's value
                int index = (leftToRight) ? i : (size - 1 - i);

                row[index] = node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            // after this level
            leftToRight = !leftToRight;
            res.push_back(row);
        }
        return res;
    }
};