#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

/*
You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.
*/

class Solution {
public:
    // Dijkstra's algorithm
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (auto& r: roads) {
            edges[r[0]].push_back(make_pair(r[1], r[2]));
            edges[r[1]].push_back(make_pair(r[0], r[2]));
        }
        
        vector<int> scores(n+1, 1e5);
        queue<int> q;
        q.push(1);

        int city;
        int ncity, score;
        vector<pair<int, int>> neighbors;
        while (!q.empty()) {
            city = q.front();
            q.pop();

            neighbors = edges[city];
            for (auto& neighbor: neighbors) {
                ncity = neighbor.first;
                score = min(scores[city], neighbor.second);
                if (score < scores[ncity]) {
                    scores[ncity] = score;
                    q.push(ncity);
                }
            }
        }

        return scores[n];
    }

    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> gr(n+1);
        for(auto edge : roads){ 
            gr[edge[0]].push_back({edge[1], edge[2]}); // u-> {v, dis}
            gr[edge[1]].push_back({edge[0], edge[2]}); // v-> {u, dis}
        }

        vector<int> vis(n+1, 0);
        queue<int> q;
        q.push(1); 
        vis[1] = 1;
        while(!q.empty()){
            int node = q.front(); 
            q.pop();
            for(auto& ni : gr[node]){
                ans = min(ans, ni.second);
                if (vis[ni.first] == 0) {
                    vis[ni.first] = 1;
                    q.push(ni.first);
                }
            }
        }

        return ans;
    }
};