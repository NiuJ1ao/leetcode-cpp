#include <vector>
using namespace std;

/*
You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.
*/


class Solution {
public:
    // count the number of nodes in connected graphs.
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adjs(n);

        for (auto e: edges) {
            adjs[e[0]].push_back(e[1]);
            adjs[e[1]].push_back(e[0]);
        }

        long res = 0, counted = 0, numNodes = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                numNodes = dfs(adjs, visited, i);
                res += (n - counted - numNodes) * numNodes;
                counted += numNodes;
            }
        }

        return res;
    }

    long long countPairs1(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adjs(n);

        for (auto e: edges) {
            adjs[e[0]].push_back(e[1]);
            adjs[e[1]].push_back(e[0]);
        }

        long long res = (long long)n * (n - 1) / 2, c = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                c = dfs(adjs, visited, i);
                res -= c * (c - 1) / 2;
            }
        }

        return res;
    }

    long dfs(vector<vector<int>>& adjs, vector<bool>& visited, int node) {
        if (visited[node]) return 0;

        visited[node] = true;

        long count = 1;
        for (int j: adjs[node]) {
            count += dfs(adjs, visited, j);
        }

        return count;
    }
};