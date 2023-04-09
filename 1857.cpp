#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

/*
There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
*/

class Solution {
public:
    // Topological Sort
    // We start with nodes with zero indegrees, and then "remove" outgoing edges. 
    // After that, we pick a new set of nodes with zero indegree, and repeat the process.
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adjs(n), counts(n, vector<int>(26));
        vector<int> indegrees(n);
        for (auto& e: edges) {
            adjs[e[0]].push_back(e[1]);
            indegrees[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegrees[i] == 0)
                q.push(i);
        }

        int res = 0, visited = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            res = max(res, ++counts[curr][colors[curr] - 'a']);
            visited++;
            for (int j: adjs[curr]) {
                // Set count for each color to maximum value between i and j.
                for (int i = 0; i < 26; i++) {
                    counts[j][i] = max(counts[j][i], counts[curr][i]);
                }
                if (--indegrees[j] == 0) {
                    q.push(j);
                }
            }
        }

        return visited < n ? -1 : res;
    }


    // DFS
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adjs(n), counts(n, vector<int>(26));
        for (auto& e: edges) {
            adjs[e[0]].push_back(e[1]);
        }
        vector<int> visited(n);
        int res = 0;
        for (int i = 0; i < n && res != INT_MAX; i++)
            res = max(res, dfs(i, colors, adjs, visited, counts));
        return res == INT_MAX ? -1 : res;
    }

    int dfs(int node, string& colors, vector<vector<int>>& adjs, vector<int>& visited, vector<vector<int>>& counts) {
        if (visited[node] == 1) return INT_MAX;
        if (visited[node] == 2) return counts[node][colors[node] - 'a'];

        visited[node] = 1;
        for (int adj: adjs[node]) {
            if (dfs(adj, colors, adjs, visited, counts) == INT_MAX) return INT_MAX;
            for (int k = 0; k < 26; k++) {
                counts[node][k] = max(counts[node][k], counts[adj][k]);
            }
        }
        counts[node][colors[node] - 'a']++;
        visited[node] = 2;
        return counts[node][colors[node] - 'a'];
    }
};