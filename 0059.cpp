#include <vector>
using namespace std;

/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));

        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int direction = 0, elem = 1;
        while (top <= bottom && left <= right) {
            if (direction == 0) {
                for (int i = left; i <= right; i++) res[top][i] = elem++;
                direction = 1;
                top++;
            } else if (direction == 1) {
                for (int i = top; i <= bottom; i++) res[i][right] = elem++;
                direction = 2;
                right--;
            } else if (direction == 2) {
                for (int i = right; i >= left; i--) res[bottom][i] = elem++;
                direction = 3;
                bottom--;
            } else if (direction == 3) {
                for (int i = bottom; i >= top; i--) res[i][left] = elem++;
                direction = 0;
                left++;
            }
        }

        return res;
    }
};