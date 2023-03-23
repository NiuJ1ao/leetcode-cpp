#include <vector>
using namespace std;

/*
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

// # of subarraies in a array of size n = n(n+1) / 2

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long res = 0, n = 0;
        int l = 0, r = 0;

        while (l < nums.size()) {
            if (r == nums.size()) {
                n = r - l;
                res += n * (n + 1) / 2;
                break;
            }
            if (nums[l] != 0) {
                l++;
                r++;
            } else {
                if (nums[r] == 0) {
                    r++;
                } else {
                    n = r - l;
                    res += n * (n + 1) / 2;
                    l = r;
                }
            }
        }
        
        return res;
    }
};