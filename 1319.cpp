#include <vector>
using namespace std;

/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
*/


class Solution {
public:
    // Count the number of connected networks.
    // To connect two unconneccted networks, we need to set one cable.
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        vector<vector<int>> edges(n);
        for (auto c: connections) {
            edges[c[0]].push_back(c[1]);
            edges[c[1]].push_back(c[0]);
        }
        vector<int> visited(n, 0);

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += dfs(i, visited, edges);
        }
        return res - 1;
    }

    int dfs(int i, vector<int>& visited, vector<vector<int>>& edges) {
        if (visited[i]) return 0;
        visited[i] = 1;
        for (auto& j: edges[i]) dfs(j, visited, edges);
        return 1;
    }
};