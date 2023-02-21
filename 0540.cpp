#include <vector>
using namespace std;

/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        for (int i = 0; i < nums.size()-1; i+=2) {
            if (nums[i] != nums[i+1]) {
                return nums[i];
            }
        }
        return nums[nums.size()-1];
    }

    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                left = mid + 1;
            else
                right = mid;
        }
        
        return nums[left];
    }

    // mid^1 explanation:
    // odd xor 1 = odd-1
    // even xor 1 = even+1
    // nums[mid] == nums[mid^1] <=> (mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1])
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-2; 
        
        while(low <= high){
            
            int mid = low + (high-low) / 2;
            
			// If we are on left side, move right
            if(nums[mid] == nums[mid^1]) low = mid+1;
			// if we are on right side, move left
            else high = mid-1;
        }
        
        return nums[low];
    }
};