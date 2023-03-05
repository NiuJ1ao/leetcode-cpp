#include <vector>
#include <algorithm>
using namespace std;

/*
You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.
*/

class Solution {
public:
    // sliding window
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        long minPos = -1, maxPos = -1, exceedPos = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (minK < nums[i] && nums[i] < maxK) {
                if (nums[i] == minK) minPos = i;
                if (nums[i] == maxK) maxPos = i;
                // The starting element of the subarray can be choosen in interval [jbad + 1, min(jmin, jmax)]
                // The subarray ends at A[i]
                // There are min(jmin, jmax) - jbad choices
                res += max(0L, min(minPos, maxPos) - exceedPos);
            } else {
                exceedPos = i;
            }
        }

        return res;
    }
};