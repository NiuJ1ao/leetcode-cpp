#include <vector>
#include <limits.h>
using namespace std;

/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        int l = 0, r = 0, sum = 0;

        while (r < n) {
            sum += nums[r++];
            
            while (sum >= target) {
                res = min(res, r - l);
                sum -= nums[l++];
            }
        }

        return res == INT_MAX ?  0 : res;
    }
};