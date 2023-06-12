#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int l = j + 1, r = n - 1;
                long long remain = (long long)target - nums[i] - nums[j];
                while (l < r) {
                    if (nums[l] + nums[r] == remain) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l + 1 < r && nums[l] == nums[l+1]) ++l;
                        ++l, --r;
                    } else if (nums[l] + nums[r] > remain) {
                        --r;
                    } else {
                        ++l;
                    }
                }
                while (j + 1 < n && nums[j] == nums[j+1]) ++j;
            }
            while (i + 1 < n && nums[i] == nums[i+1]) ++i;
        }

        return res;
    }
};