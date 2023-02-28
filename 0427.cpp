#include <stdio.h>
#include <vector>
using namespace std;

/*
Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.
Return the root of the Quad-Tree representing the grid.
Notice that you can assign the value of a node to True or False when isLeaf is False, and both are accepted in the answer.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:
val: True if the node represents a grid of 1's or False if the node represents a grid of 0's.
isLeaf: True if the node is leaf node on the tree or False if the node has the four children.

We can construct a Quad-Tree from a two-dimensional area using the following steps:
If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.
*/

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int N = grid.size();
        return helper(grid, 0, 0, N);
    }

    Node* helper(vector<vector<int>>& grid, int top, int left, int n) {
        int bottom = top + n;
        int right = left + n;
        bool isLeaf = checkLeaf(grid, top, left, bottom, right);

        if (isLeaf) {
            Node* leaf = new Node(grid[top][left], isLeaf);
            return leaf;
        }

        n /= 2;
        Node* topLeft = helper(grid, top, left, n);
        Node* topRight = helper(grid, top, left + n, n);
        Node* bottomLeft = helper(grid, top + n, left, n);
        Node* bottomRight = helper(grid, top + n, left + n, n);
        Node* t = new Node(grid[top][left], isLeaf, topLeft, topRight, bottomLeft, bottomRight);
        return t;
    }

    bool checkLeaf(vector<vector<int>>& grid, int top, int left, int bottom, int right) {
        for (int i = top; i < bottom; i++) {
            for (int j = left; j < right; j++) {
                if (grid[top][left] != grid[i][j])
                    return false;
            }
        }
        return true;
    }
};