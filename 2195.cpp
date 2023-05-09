#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
You are given an integer array nums and an integer k. Append k unique positive integers that do not appear in nums to nums such that the resulting total sum is minimum.

Return the sum of the k integers appended to nums.
*/

class Solution {
public:
    // \sum_1^n = n x (n - 1) / 2
    long long minimalKSum(vector<int>& nums, int k) {
        long long res = 0, cur = 1;
        nums.push_back(INT_MAX);
        sort(begin(nums), end(nums));
        for (int i = 0; k > 0 && i < nums.size(); ++i) {
            int take = max(0, min(k, nums[i] - (int)cur));
            res += (cur + take) * (cur + take - 1) / 2 - cur * (cur - 1) / 2;
            k -= take;
            cur = (long long)nums[i] + 1;
        }
        return res;
    }
};