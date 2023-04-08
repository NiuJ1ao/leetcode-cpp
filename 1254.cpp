#include <vector>
using namespace std;

/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
*/

class Solution {
public:
    // DFS
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> valid(n, vector<int>(m, -1));
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) valid[i][0] = 0;
            if (grid[i][m-1] == 0) valid[i][m-1] = 0;
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0) valid[0][j] = 0;
            if (grid[n-1][j] == 0) valid[n-1][j] = 0;
        }
                

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && valid[i][j] == -1) {
                    res += dfs(grid, n, m, i, j, valid);
                }
            }
        }

        return res;
    }

    int dfs(vector<vector<int>>& grid, int n, int m, int i, int j, vector<vector<int>>& valid) {
        if (valid[i][j] != -1) return valid[i][j];

        valid[i][j] = 1;
        if (i > 0 && grid[i-1][j] == 0) 
            valid[i][j] &= dfs(grid, n, m, i - 1, j, valid);
        if (i + 1 < n && grid[i+1][j] == 0) 
            valid[i][j] &= dfs(grid, n, m, i + 1, j, valid);
        if (j > 0 && grid[i][j-1] == 0) 
            valid[i][j] &= dfs(grid, n, m, i, j - 1, valid);
        if (j + 1 < m && grid[i][j + 1] == 0) 
            valid[i][j] &= dfs(grid, n, m, i, j + 1, valid);
        return valid[i][j];
    }

    // DFS - optimized
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 0){
                    res += dfs(grid, i, j) ? 1 : 0;
                }
            }
        }
        return res;
    }

    bool dfs(vector<vector<int>>& g, int i, int j){
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size()){
            return false;
        }
        if (g[i][j] == 1){
            return true;
        }
        g[i][j] = 1;
        /* IMPORTANT NOTE: 
        WHY I CANNOT USE `return dfs(g, i+1, j) && dfs(g, i, j+1) && dfs(g, i-1, j) && dfs(g, i, j-1);`???
        BECAUSE IF ANY OF THE FIRST DFS() RETURNS FALSE, FOLLOWING ONES WILL NOT EXECUTE!!! THEN WE DON'T
        HAVE THE CHANCE TO MARK THOSE 0s TO 1s!!!
        */
        bool d1 = dfs(g, i+1, j);
        bool d2 = dfs(g, i, j+1);
        bool d3 = dfs(g, i-1, j);
        bool d4 = dfs(g, i, j-1);
        return d1 && d2 && d3 && d4;
    }
};