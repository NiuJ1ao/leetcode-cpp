#include <unordered_map>
#include <vector>
using namespace std;

/*
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        int res = 0;
        for (int i: nums1) {
            for (int j: nums2) {
                mp[i + j]++;
            }
        }

        for (int i: nums3) {
            for (int j: nums4) {
                res += mp[-(i + j)];
            }
        }
        return res;
    }
};