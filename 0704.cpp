#include <vector>
using namespace std;

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        int i;

        while (l < r) {
            i = (l + r) / 2;
            if (nums[i] == target) {
                return i;
            }

            if (nums[i] < target) {
                l = i + 1;
            } else {
                r = i;
            }
        }

        return -1;
    }
};