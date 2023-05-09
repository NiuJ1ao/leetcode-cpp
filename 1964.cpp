#include <vector>
using namespace std;

/*
You want to build some obstacle courses. You are given a 0-indexed integer array obstacles of length n, where obstacles[i] describes the height of the ith obstacle.

For every index i between 0 and n - 1 (inclusive), find the length of the longest obstacle course in obstacles such that:

You choose any number of obstacles between 0 and i inclusive.
You must include the ith obstacle in the course.
You must put the chosen obstacles in the same order as they appear in obstacles.
Every obstacle (except the first) is taller than or the same height as the obstacle immediately before it.

Return an array ans of length n, where ans[i] is the length of the longest obstacle course for index i as described above.
*/

class Solution {
public:
    // Same as longest increasing subsequence [300]
    // binary search + mono increase stack
    // for x in obstacles, find the index of smallest number > x.
    // if the number at index with x, res[i] = index + 1
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> res, mono;

        for (int x: obstacles) {
            int l = 0, r = mono.size();
            while (l < r) {
                int m = (l + r) / 2;
                if (mono[m] <= x)
                    l = m + 1;
                else
                    r = m;
            }

            res.push_back(l + 1);
            if (mono.size() == l)
                mono.push_back(x);
            mono[l] = x;
        }

        return res;
    }
};