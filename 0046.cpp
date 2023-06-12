#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/

class Solution {
public:
    // Swap
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, res, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& res, int idx) {
		if (idx >= nums.size()) {
		    // one permutation instance
		    res.push_back(nums);
		    return;
		}
		
		for (int i = idx; i < nums.size(); i++) {
		    swap(nums[idx], nums[i]);
		    backtrack(nums, res, idx + 1);
		    // reset
		    swap(nums[idx], nums[i]);
		}
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> step;
        backtrack(nums, res, step);
        return res;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& step) {
        if (step.size() == nums.size()) {
            res.push_back(step);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(step.begin(), step.end(), nums[i]) == step.end()) {
                step.push_back(nums[i]);
                backtrack(nums, res, step);
                step.pop_back();
            }
        }
    }
};