#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> kSum(vector<int> nums, int target, int k) {
        sort(nums.begin(), nums.end());
        vector<int> step;
        dfs(nums, step, target, k, 0, nums.size() - 1);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& step, int target, int k, int l, int r) {
        if (k == 2) {
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    step.push_back(nums[l]);
                    step.push_back(nums[r]);
                    res.push_back(step);
                    step.pop_back();
                    step.pop_back();
                    while (l + 1 < r && nums[l] == nums[l+1]) ++l; // Skip duplicate nums[l]
                    ++l, --r;
                } else if (nums[l] + nums[r] > target) {
                    // Sum is bigger than remain, need to decrease sum
                    --r;
                } else {
                    ++l;
                }
            }
        }

        while (l < r) {
            step.push_back(nums[l]);
            dfs(nums, step, target-nums[l], k - 1, l + 1, r);
            step.pop_back();
            while (l + 1 < r && nums[l] == nums[l+1]) ++l; // Skip duplicate nums[l]
            ++l;
        }
    }
};