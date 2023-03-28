#include <vector>
using namespace std;

/*
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.
*/

class Solution {
public:
    // DFS
    // Iterating unvisited nodes by DFS, identify any cycles that include the current node.
    // We maintain an array to store the time at which each node was first visited during the DFS.
    // If a cycle is found, the length of cycle is the difference between the current time step and the time step at the node was first visited.
    int longestCycle(vector<int>& edges) {
        int res = -1;
        int timeStep = 1;
        int n = edges.size();
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            int startTime = timeStep;
            int curr = i;
            while (curr != -1 && !visited[curr]) {
                visited[curr] = timeStep++;
                curr = edges[curr];
            }
            if (curr != -1 && visited[curr] >= startTime)
                res = max(res, timeStep - visited[curr]);
        }

        return res;
    }
};