#include <vector>
#include <string.h>
using namespace std;

/*
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
*/

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int row = mat.size(), col = mat[0].size();
        for (int t = 0; t < 4; t++) {
            if (mat == target) {
                return true;
            }
            mat = rotateClockwise(mat);
        }
        return false;
    }

    vector<vector<int>> rotateClockwise(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> rot(row);
        for (int i = row - 1; i >= 0; i--) {
            for (int j = 0; j < col; j++) {
                rot[j].push_back(mat[i][j]);
            }
        }
        return rot;
    }


    // inplace comparison
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool c[4];
        memset(c, true, sizeof(c));
        int n = mat.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (mat[i][j] != target[i][j]) c[0] = false;
                if (mat[i][j] != target[n-j-1][i]) c[1] = false;
                if (mat[i][j] != target[n-i-1][n-j-1]) c[2] = false;
                if (mat[i][j] != target[j][n-i-1]) c[3] = false;
            }
        }
        return c[0]||c[1]||c[2]||c[3];
    }
};