#include <vector>
#include <algorithm>
using namespace std;

/*
An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.

Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .

Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.
*/

class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int Find(int x) {
        return parent[x] = parent[x] == x ? x : Find(parent[x]);
    }

    bool Union(int x, int y) {
        int xset = Find(x), yset = Find(y);
        if (xset != yset) {
            rank[xset] < rank[yset] ? parent[xset] = yset : parent[yset] = parent[xset];
            rank[xset] += rank[xset] == rank[yset];
            return true;
        }
        return false;
    }
};


class Solution {
public:
    // UnionFind
    // join all the edges whose weight is less than limit and 
    // if we are still not able to reach one node from the other 
    // it essentially means that there is no path between them where edge weight is less than limit.
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        UnionFind dsu(n);
        
        // Add query indices to help with organizing/ordering results.
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }

        // Sort inputs
        sort(queries.begin(), queries.end(), [](auto& l, auto& r) {return l[2] < r[2];});
        sort(edgeList.begin(), edgeList.end(), [](auto& l, auto& r) {return l[2] < r[2];});

        int i = 0;
        vector<bool> res(queries.size());
        for (auto& q: queries) {
            while (i < edgeList.size() && edgeList[i][2] < q[2]) {
                dsu.Union(edgeList[i][0], edgeList[i][1]);
                i++;
            }

            res[q[3]] = dsu.Find(q[0]) == dsu.Find(q[1]);
        }

        return res;
    }
};