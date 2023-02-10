#include <vector>
#include <cmath>
#include <queue>
#include <limits.h>
using namespace std;

/*
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, 
find a water cell such that its distance to the nearest land cell is maximized, and return the distance. 
If no land or water exists in the grid, return -1.
*/

class Solution {
public:
    // brute-force
    typedef pair<int, int> loc;
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<loc> lands;
        vector<loc> waters;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                loc location = {i, j};
                if (grid[i][j]) {
                    lands.push_back(location);
                } else {
                    waters.push_back(location);
                }
            }
        }

        int maxDist = -1;
        if (lands.size() == 0 || waters.size() == 0) {
            return maxDist;
        }
        
        for (loc water: waters) {
            int nearest = 2 * n;
            for (loc land: lands) {
                int dist = abs(land.first - water.first) + abs(land.second - water.second);
                if (dist < nearest) {
                    nearest = dist;
                }
            }
            if (nearest > maxDist) {
                maxDist = nearest;
            }
        }

        return maxDist;
    }

    // BFS
    // start with all the 1's, and at each step, we will iterate in all four directions (up, left, right, down) for each 1. 
    // The moment we reach a water cell 0, we can say that the number of steps we have taken so far is the minimum distance 
    // of this water cell from any land cell in the matrix. This way, we will iterate over the whole matrix until all cells 
    // are covered; the number of steps we would need to cover the last water cell is the maximum distance we need.

    // Four directions: Up, Down, Left and Right.
    const pair<int, int> direction[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maxDistance(vector<vector<int>>& grid) {
        // A copy matrix of the grid to mark water cells as land once visited.
        int visited[grid.size()][grid[0].size()];
        
        // Insert all the land cells in the queue.
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // Copy grid to the visited matrix.
                visited[i][j] = grid[i][j];
                if (grid[i][j]) {
                    q.push({i, j});
                }
            }
        }
        
        int distance = -1;
        while (!q.empty()) {
            int qSize = q.size();
            
            // Iterate over all the current cells in the queue.
            while (qSize--) {
                pair<int, int> landCell = q.front();
                q.pop();
                
                // From the current land cell, traverse to all the four directions
                // and check if it is a water cell. If yes, convert it to land
                // and add it to the queue.
                for (pair<int, int> dir : direction) {
                    int x = landCell.first + dir.first;
                    int y = landCell.second + dir.second;
                    
                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && visited[x][y] == 0) {
                        // Marking as 1 to avoid re-iterating it.
                        visited[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            
            // After each iteration of queue elements, increment distance 
            // as we covered 1 unit distance from all cells in every direction.
            distance++;
        }
        
        // If the distance is 0, there is no water cell.
        return distance == 0 ? -1 : distance;
    }

    // DP: similar to 0542
    // curr dist = neighour + 1
    // two pass: 1) from top-left, check left and top cell distances. 2) from bottom-right, check right and bottom cell distances.
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        // Although it's a square matrix, using different variable for readability.
        int cols = grid[0].size();

        // Maximum manhattan distance possible + 1.
        const int MAX_DISTANCE = rows + cols + 1;
        
        vector<vector<int>> dist(rows, vector<int> (cols, MAX_DISTANCE));
        
        // First pass: check for left and top neighbours
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Distance of land cells will be 0.
                if (grid[i][j]) {
                    dist[i][j] = 0;
                } else {
                    // Check left and top cell distances if they exist and update the current cell distance.
                    dist[i][j] = min(dist[i][j], min(i > 0 ? dist[i - 1][j] + 1 : MAX_DISTANCE,
                                                     j > 0 ? dist[i][j - 1] + 1 : MAX_DISTANCE));
                }
            }
        }

        // Second pass: check for right and bottom neighbours.
        int ans = INT_MIN;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                // Check the right and bottom cell distances if they exist and update the current cell distance.
                dist[i][j] = min(dist[i][j], min(i < rows - 1 ? dist[i + 1][j] + 1 : MAX_DISTANCE,
                                                 j < cols - 1 ? dist[i][j + 1] + 1 : MAX_DISTANCE));
                
                ans = max(ans, dist[i][j]);
            }
        }
        
        // If ans is 0, it means there is no water cell,
        // If ans is MAX_DISTANCE, it implies no land cell.
        return ans == 0 || ans == MAX_DISTANCE ? -1 : ans;
    }
};