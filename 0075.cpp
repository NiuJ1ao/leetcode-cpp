#include <vector>
using namespace std;

/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/

class Solution {
public:
    // Dutch national flag problem
    // elements are classified into three categories: bottom, middle and top;
    // all "bottom" elements come before (have an index less than the index of) all "middle" elements, which come before all "top" elements.
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size() - 1;

        while (j <= k) {
            if (nums[j] == 0) {
                swap(nums[i++], nums[j++]);
            } else if (nums[j] == 2) {
                swap(nums[j], nums[k--]);
            } else {
                j++;
            }
        }
    }

    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);

        for (int x: nums) {
            freq[x]++;
        }

        int j = 0;
        for (int i = 0; i < nums.size() && j < 3; i++) {
            while (freq[j] == 0) {
                j++;
            } 
            nums[i] = j;
            freq[j]--;
        }
    }
};