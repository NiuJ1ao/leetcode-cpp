#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [from_i, to_i, price_i] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Dijkstra's algorithm with constraints
Note: We look for the shortest path in the constraints. So, we can focus on check if stops exceed the limits. Priority queue is already sorted by the prices. 
      If the question is about vanilla Dijkstra's, we need to track the shortest distance of every node from the source (processed in the neighbour loop).
*/

class Solution {
public:

    typedef tuple<int, int, int> myTuple;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
                vector<vector<pair<int, int>>> adj(n);
        for (auto f: flights) {
            adj[f[0]].push_back(make_pair(f[1], f[2]));
        }

        vector<int> steps(n, n);
        priority_queue<myTuple, vector<myTuple>, greater<myTuple>> q;
        q.push(make_tuple(0, src, 0));
        
        while (!q.empty()) {
            myTuple curr = q.top();
            int price = get<0>(curr);
            int u = get<1>(curr);
            int step = get<2>(curr);
            q.pop();

            if (step > steps[u] || step > k + 1) continue;
            if (u == dst) return price;

            // found cheap flights with fewer steps
            steps[u] = step;
            for (auto p: adj[u]) {
                q.push(make_tuple(price + p.second, p.first, step + 1));
            }
        }

        return -1;
    }
};