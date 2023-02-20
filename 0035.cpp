#include <vector>
using namespace std;

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity. [Binary search]
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size();
        int idx = j / 2;
        if (target < nums[i]) return 0;
        if (target > nums[j - 1]) return j;
        while (i < j - 1) {
            if (target == nums[idx]) {
                return idx;
            }
            if (target < nums[idx]) {
                j = idx;
            } else {
                i = idx;
            }
            idx = i + (j - i) / 2;
        }
        if (target == nums[idx]) {
                return idx;
        }
        return idx + 1;
    }
};