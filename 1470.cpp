#include <vector>
using namespace std;

/*
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(nums.size());
        int i = 0, j = n;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (idx % 2 == 0) {
                res[idx] = nums[i];
                i++;
            } else {
                res[idx] = nums[j];
                j++;
            }
        }
        return res;
    }

    // inplace filling using bitwise operations
    // space O(1)
    vector<int> shuffle(vector<int>& nums, int n) {
        int len = nums.size();
        
        for(int i = n; i < len; i++) {
            nums[i] = (nums[i] << 10) | nums[i - n];
        }
        
        int index = 0;
        for(int i = n; i < len; i++, index += 2) {
            nums[index] = nums[i] & 1023;
            nums[index + 1] = nums[i] >> 10;
        }
        
        return nums;
    }
};