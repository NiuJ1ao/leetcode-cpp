#include <vector>
using namespace std;

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int fromBegin = 1, fromEnd = 1;

        for (int i = 0; i < n; i++) {
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n-i-1] *= fromEnd;
            fromEnd *= nums[n-i-1];
        }

        return res;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fromBegin(n), fromEnd(n);
        fromBegin[0] = 1;
        fromEnd[0] = 1;

        for (int i = 1; i < n; i++) {
            fromBegin[i] = fromBegin[i-1] * nums[i - 1];
            fromEnd[i] = fromEnd[i - 1] * nums[n - i];
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = fromBegin[i] * fromEnd[n-i-1];
        }
        return res;
    }
};