#include <vector>
using namespace std;

/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Solution {
public:
    // backtracking
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> step;
        helper(nums, res, step, 0);
        return res;
    }

    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& step, int idx) {
        res.push_back(step);
        for (int i = idx; i < nums.size(); i++) {
            step.push_back(nums[i]);
            helper(nums, res, step, i + 1);
            step.pop_back();
        }
    }
};