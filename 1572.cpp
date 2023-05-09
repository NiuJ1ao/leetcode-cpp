#include <vector>
using namespace std;

/*
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0, n = mat.size();
        for (int i = 0; i < n; i++) {
            res += mat[i][i] + mat[n - i - 1][i];
        }

        return n % 2 == 0 ? res : res - mat[n / 2][n / 2];
    }
};