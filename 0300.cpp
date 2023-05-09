#include <vector>
#include <algorithm>
using namespace std;

/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.
*/

class Solution {
public:
    // DP - dp[i]: the longest increasing subsequence of nums[0:i]
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    // binary search + mono stack
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> mono;

        int l, r, m;
        for (int x: nums) {
            l = 0, r = mono.size();
            while (l < r) {
                m = (l + r) / 2;
                if (mono[m] < x) {
                    l = m + 1;
                } else {
                    r = m;
                }
            } 

            res = max(res, l + 1);
            if (l == mono.size()) {
                mono.push_back(x);
            }
            mono[l] = x;
        }
        
        return res;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x: nums) {
            auto it = lower_bound(sub.begin(), sub.end(), x);
            if(it==sub.end()) sub.push_back(x);
            else *it = x;
        }
        
        return sub.size();
    }
};