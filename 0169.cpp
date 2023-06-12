#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

class Solution {
public:
    // Moore voting algorithm
    // Initialize an element m and a counter i with i = 0
    // For each element x of the input sequence:
    //  If i = 0, then assign m = x and i = 1
    //  else if m = x, then assign i = i + 1
    //  else assign i = i − 1
    // Return m
    int majorityElement(vector<int>& nums) {
        int counter = 0, majority;
        for (int num : nums) {
            if (!counter) {
                majority = num;
            }
            counter += num == majority ? 1 : -1;
        }
        return majority;
    }

    // only partial sort is needed
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    }

    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            if (++counter[num] > nums.size() / 2) {
                return num;
            }
        }
        return 0;
    }
};