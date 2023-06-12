#include <string>
#include <queue>
using namespace std;

/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string val = "";
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == ',') {
                q.push(val);
                val = "";
            } else {
                val += data[i];
            }
        }
        if (val.length() > 0) q.push(val);

        return preorderTraversal(q);
    }

    TreeNode* preorderTraversal(queue<string>& q) {
        string val = q.front();
        q.pop();
        if (val == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root -> left = preorderTraversal(q);
        root -> right = preorderTraversal(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));