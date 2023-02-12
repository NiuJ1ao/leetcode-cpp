#include <vector>
#include <cmath>
#include <queue>
using namespace std;

/*
There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

There is a meeting for the representatives of each city. The meeting is in the capital city.

There is a car in each city. You are given an integer seats that indicates the number of seats in each car.

A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.

Return the minimum number of liters of fuel to reach the capital city.
*/

class Solution {
public:
    // DFS
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& road: roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        long long fuel = 0;
        dfs(0, -1, adj, seats, &fuel);
        return fuel;
    }

    long long dfs(int node, int parent, vector<vector<int>>& adj, int seats, long long* fuel) {
        int rep = 1;
        for (auto& child: adj[node]) {
            // check for circle
            if (child != parent) {
                rep += dfs(child, node, adj, seats, fuel);
            }
        }

        if (node != 0) {
            // Count the fuel it takes to move to the parent node.
            // Root node does not have any parent so we ignore it.
            (*fuel) += ceil((double) rep / seats);
        }

        return rep;
    }

    // BFS - bottom-up
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        vector<int> degree(n);

        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
            degree[road[0]]++;
            degree[road[1]]++;
        }

        queue<int> q;
        for (int i = 1; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        vector<int> representatives(n, 1);
        long long fuel = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            fuel += ceil((double)representatives[node] / seats);
            for (auto& neighbor : adj[node]) {
                degree[neighbor]--;
                representatives[neighbor] += representatives[node];
                if (degree[neighbor] == 1 && neighbor != 0) {
                    q.push(neighbor);
                }
            }
        }
        return fuel;
    }
};