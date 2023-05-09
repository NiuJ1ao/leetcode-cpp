#include <vector>
using namespace std;

/*
Given an m x n matrix, return all elements of the matrix in spiral order.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int top = 0, left = 0, down = n - 1, right = m - 1;
        int direction = 1;
        vector<int> res(n * m);
        int idx = 0;
        while (left <= right && top <= down) {
            if (direction == 1) {
                for(int i=left; i<=right; i++) res[idx++] = matrix[top][i];
                direction=2;
                top++;
            } else if (direction == 2) {
                for(int i=top; i<=down; i++) res[idx++] = matrix[i][right];
                direction=3;
                right--;
            } else if (direction == 3) {
                for(int i=right; i>=left; i--) res[idx++] = matrix[down][i];
                direction=4;
                down--;
            } else if (direction == 4) {
                for(int i=down; i>=top; i--) res[idx++] = matrix[i][left];
                direction=1;
                left++;
            }
        }
        return res;
    }
};