#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Game about shortest path.

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        // destination
        int dest = n * n;
        // starting point
        int curr = 1;

        // BFS: preferred for unweighted graphs, compared with Dijkstra's algorithm.
        //      It is difficult to find a heuristic function for A*.
        unordered_map<int, int> step;
        step[curr] = 0;
        queue<int> q;
        q.push(curr);
        while (!q.empty()) {
            curr = q.front();
            q.pop();

            for (int i = 1; i <= 6 && curr + i <= dest; i++) {
                int next = curr + i;

                // get coord
                int row = n - (next - 1) / n - 1;
                int col = (next - 1) % n;
                if ((next - 1) / n % 2 != 0) {
                    // descend
                    col = n - col - 1;
                }

                // snake or ladder
                if (board[row][col] != -1) {
                    next = board[row][col];
                }

                // terminate
                if (next == dest) {
                    return step[curr] + 1;
                }

                // not visited
                if (step.find(next) == step.end()) {
                    step[next] = step[curr] + 1;
                    q.push(next);
                }
            }
        }

        return -1;
    }
};