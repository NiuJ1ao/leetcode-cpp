#include <vector>
#include <algorithm>
using namespace std;

/*
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.
*/

class Solution {
public:
    // sort
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i+=2) {
            res += nums[i];
        }
        return res;
    }

    // counting sort
    int arrayPairSum(vector<int>& nums) {
        const int k = 1e4;
        int freq[2 * k + 1] = {0};
        for (int i: nums) {
            // make sure values are positive since the smallest nums[i] = 1e-4
            freq[i + k]++;
        }

        int res = 0;
        bool isEven = true;
        for (int i = 0; i <= 2 * k; i++) {
            while (freq[i]) {
                res += isEven ? i - k : 0;
                isEven = !isEven;
                freq[i]--;
            }
        }
        return res;
    }
};