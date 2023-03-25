#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.
*/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int res = 0;

        vector<vector<int>> to(n);
        vector<vector<int>> back(n);
        for (auto c: connections) {
            to[c[0]].push_back(c[1]);
            back[c[1]].push_back(c[0]);
        }

        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = true;

            for (int i: to[curr]) {
                if (!visited[i]) {
                    res++;
                    q.push(i);
                }
            }

            for (int i: back[curr]) {
                if (!visited[i])
                    q.push(i);
            }
        }

        return res;
    }


    // dfs with signed direction
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& c: connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }

        return dfs(adj, vector<bool>(n) = {}, 0);
    }

    int dfs(vector<vector<int>>& adj, vector<bool>& visited, int from) {
        int change = 0;
        visited[from] = true;
        for (int to: adj[from]) {
            if (!visited[abs(to)]) {
                change += dfs(adj, visited, abs(to)) + (to > 0);
            }
        }
        return change;
    }
};