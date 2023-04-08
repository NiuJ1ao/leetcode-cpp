#include <vector>
#include <numeric>
using namespace std;

/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

class Solution {
public:
    // lood-fill the land (change 1 to 0) from the boundary of the grid.
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][0]) dfs(grid, n, m, i, 0);
            if (grid[i][m-1]) dfs(grid, n, m, i, m-1);
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j]) dfs(grid, n, m, 0, j);
            if (grid[n-1][j]) dfs(grid, n, m, n-1, j);
        }
        return accumulate(begin(grid), end(grid), 0, [](int s, vector<int> &r) { return s + accumulate(begin(r), end(r), 0); });
    }

    // flood cells
    void dfs(vector<vector<int>>& grid, int n, int m, int i, int j) {
        if (i < 0 || i == n || j < 0 || j == m) 
            return;
        
        if (grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        dfs(grid, n, m, i + 1, j);
        dfs(grid, n, m, i - 1, j);
        dfs(grid, n, m, i, j + 1);
        dfs(grid, n, m, i, j - 1);
    }
};