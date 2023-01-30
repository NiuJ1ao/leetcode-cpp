#include <vector>
using namespace std;

/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0];
        for (auto it = nums.begin() + 1; it != nums.end(); it++) {
            if (*it == prev) {
                nums.erase(it);
                it--;
            } else {
                prev = *it;
            }
        }

        return nums.size();
    }

    // move the unique elements to the front of array and discard the rest.
    int removeDuplicates(vector<int>& nums) {
        int insertIndex = 1;
        for(int i = 1; i < nums.size(); i++){
            // We skip to next index if we see a duplicate element
            if(nums[i - 1] != nums[i]) {    
                // Storing the unique element at insertIndex index and incrementing the insertIndex by 1 
                nums[insertIndex++] = nums[i];
            }
        }
        return insertIndex;
    }
};