#include <vector>
#include <algorithm>
using namespace std;

/*
You are given a 0-indexed array nums comprising of n non-negative integers.

In one operation, you must:

Choose an integer i such that 1 <= i < n and nums[i] > 0.
Decrease nums[i] by 1.
Increase nums[i - 1] by 1.

Return the minimum possible value of the maximum integer of nums after performing any number of operations.
*/

class Solution {
public:
    // Prefix Sum
    // We actully move the value of A[i] to A[i - 1] by 1, the sum won't change.
    // If A[i] < A[i + 1], then we can repeatly do the operations, until A[i] >= A[i+1]. So finally the array A will become decrescent order.
    // We calculate the prefix sum arrray and their average. The average is the lower bound of the result.
    int minimizeArrayValue(vector<int>& A) {
        long sum = 0, res = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            res = max(res, (sum + i) / (i + 1));
        }
        return res;
    }
};