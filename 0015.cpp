#include <vector>
#include <algorithm>
using namespace std;

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            int target = -nums[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l + 1 < r && nums[l] == nums[l+1]) ++l;
                    ++l, --r;
                } else if (nums[l] + nums[r] > target) {
                    --r;
                } else {
                    ++l;
                }
            }
            while (i + 1 < n && nums[i] == nums[i+1]) ++i;
        }

        return res;
    }
};