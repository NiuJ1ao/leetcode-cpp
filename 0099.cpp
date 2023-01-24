#include <queue>
using namespace std;

// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

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
    // BFS
    void recoverTree(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node -> left != nullptr) { 
                if (errorDetect(node -> left, node, true)) {
                    recoverTree(root);
                    return;
                }
                q.push(node -> left);
            }
            if (node -> right != nullptr) {
                if (errorDetect(node -> right, node, false)) {
                    recoverTree(root);
                    return;
                }
                q.push(node -> right);
            }
        }
    }

    bool errorDetect(TreeNode* child, TreeNode* root, bool left) {
        queue<TreeNode*> q;
        q.push(child);

        while (!q.empty()) {
            TreeNode* node = q.front();
            // error detected
            if ((left && node -> val > root -> val) || (!left && node -> val < root -> val)) {
                int tmp = node -> val;
                node -> val = root -> val;
                root -> val = tmp;
                return true;
            }
            q.pop();

            if (node -> left != nullptr) { 
                q.push(node -> left);
            }
            if (node -> right != nullptr) {
                q.push(node -> right);
            }
        }

        return false;
    }


    // DFS
    struct returnTuple {
        TreeNode* target1;
        TreeNode* target2;
        TreeNode* prev;
        returnTuple(): target1(nullptr), target2(nullptr), prev(nullptr) {}
        returnTuple(TreeNode* target1, TreeNode* target2, TreeNode* prev): target1(target1), target2(target2), prev(prev) {}
    };

    void recoverTree(TreeNode* root) {
        returnTuple* res = inOrderTraverse(root, new returnTuple());
        if (res -> target1 && res -> target2) {
            int tmp = res -> target1 -> val;
            res -> target1 -> val = res -> target2 -> val;
            res -> target2 -> val = tmp;
        }
    }

    returnTuple* inOrderTraverse(TreeNode* root, returnTuple* res) {
        if (!root) {
            return res;
        }

        res = inOrderTraverse(root -> left, res);
        if (res -> prev && res -> prev -> val > root -> val) {
            if (!res -> target1) {
                res -> target1 = res -> prev;
            }
            res -> target2 = root;
        }
        res -> prev = root;
        res = inOrderTraverse(root -> right, res);
        return res;
    }
};