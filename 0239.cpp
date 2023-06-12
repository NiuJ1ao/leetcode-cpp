#include <vector>
#include <deque>
using namespace std;

/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
*/

class Solution {
public:
    // Sliding window
    // Use dequeue to store indices
    // 1. pop_front if element is out-of-boundary.
    // 2. pop_back if element is less than the current.
    // Then the dequeue is monotonically decreasing.
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = k - 1;
        int n = nums.size();

        vector<int> res(n - k + 1);
        deque<int> deq;

        for (int i = 0; i < n; i++) {
            l = i, r = i + k - 1;

            while (!deq.empty() && deq.front() <= i - k)
                deq.pop_front();
            while (!deq.empty() && nums[deq.back()] < nums[i])
                deq.pop_back();
            deq.push_back(i);
            
            if (i >= k - 1) res[i - k + 1] = nums[deq.front()];
        }
        

        return res;
    }
};