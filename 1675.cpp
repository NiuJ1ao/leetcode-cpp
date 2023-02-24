#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

/*
You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.
*/

class Solution {
public:
    // priority queue
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int min_n = INT_MAX, res = INT_MAX;

        // double odd nums
        for (int n: nums) {
            n = n % 2 ? n * 2 : n;
            q.push(n);
            min_n = min(min_n, n);
        }
        
        // try to decrease the maximum number as much as possible until it becomes odd. 
        while (q.top() % 2 == 0) {
            int n = q.top();
            q.pop();
            res = min(res, n - min_n);

            n /= 2;
            min_n = min(min_n, n);
            q.push(n);
        }

        return min(res, q.top() - min_n);
    }

    // set
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for (int n: nums)
            s.insert(n % 2 ? n * 2 : n);

        int res = *s.rbegin() - *s.begin();
        while (*s.rbegin() % 2 == 0) {
            s.insert(*s.rbegin() / 2);
            s.erase(*s.rbegin());
            res = min(res, *s.rbegin() - *s.begin());
        }
        return res;
    }
};