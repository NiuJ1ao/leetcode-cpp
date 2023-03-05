#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.

Return the minimum number of steps to reach the last index of the array.
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int dest = n - 1;

        if (n < 2) return 0;
        if (arr[0] == arr[dest]) return 1;

        unordered_map<int, vector<int>> js;
        for (int i = 0; i < n; i++) {
            js[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        vector<bool> visited(n);
        while(!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            int i = curr.first, step = curr.second;
            int val = arr[i];
            visited[i] = true;

            if (i == dest) {
                return step;
            }

            // add neighbours
            if (i > 0 && !visited[i-1] && val != arr[i-1]) {
                q.push(make_pair(i-1, step+1));
            }
            if (i < dest && !visited[i+1] && val != arr[i+1]) {
                q.push(make_pair(i+1, step+1));
            }
            for (int j: js[val]) {
                if (i != j) {
                    if (visited[j]) break;
                    q.push(make_pair(j, step+1));
                }
            }
        }
        return 0;
    }
};