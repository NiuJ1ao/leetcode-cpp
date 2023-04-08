#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> visited;
        return dfs(node, visited);
    }

    Node* dfs(Node* node, unordered_map<int, Node*>& visited) {
        if (!node) return nullptr;
        if (visited.count(node->val)) return visited[node->val];

        Node* clone = new Node(node->val);
        visited[node->val] = clone;
        int n = node->neighbors.size();
        vector<Node*> cloneNeighbors(n);
        for (int i = 0; i < n; i++) {
            cloneNeighbors[i] = dfs(node->neighbors[i], visited);
        }
        clone -> neighbors = cloneNeighbors;
        return clone;
    }
};