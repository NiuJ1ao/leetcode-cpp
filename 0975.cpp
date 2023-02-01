#include <vector>
#include <map>
using namespace std;

/*
You are given an integer array arr. From some starting index, you can make a series of jumps. The (1st, 3rd, 5th, ...) jumps in the series are called odd-numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called even-numbered jumps. Note that the jumps are numbered, not the indices.

You may jump forward from index i to index j (with i < j) in the following way:

During odd-numbered jumps (i.e., jumps 1, 3, 5, ...), you jump to the index j such that arr[i] <= arr[j] and arr[j] is the smallest possible value. If there are multiple such indices j, you can only jump to the smallest such index j.
During even-numbered jumps (i.e., jumps 2, 4, 6, ...), you jump to the index j such that arr[i] >= arr[j] and arr[j] is the largest possible value. If there are multiple such indices j, you can only jump to the smallest such index j.
It may be the case that for some index i, there are no legal jumps.
arr starting index is good if, starting from that index, you can reach the end of the array (index arr.length - 1) by jumping some number of times (possibly 0 or more than once).

Return the number of good starting indices.
*/

class Solution {
public:
    // DP https://leetcode.com/problems/odd-even-jump/solutions/217981/java-c-python-dp-using-map-or-stack/
    // 太妙了
    // Time O(NlogN)
    // Space O(N)
    int oddEvenJumps(vector<int>& arr) {
        int n  = arr.size(), res = 1;
        vector<int> higher(n), lower(n);
        higher[n - 1] = lower[n - 1] = 1;
        map<int, int> map;
        map[arr[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            auto hi = map.lower_bound(arr[i]), lo = map.upper_bound(arr[i]);
            if (hi != map.end()) higher[i] = lower[hi->second]; // odd-number jump
            if (lo != map.begin()) lower[i] = higher[(--lo)->second]; // even-number jump
            if (higher[i]) res++;
            map[arr[i]] = i;
        }
        return res;
    }
};