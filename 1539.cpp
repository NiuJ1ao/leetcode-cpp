#include <vector>
using namespace std;

/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
*/

class Solution {
public:
    // O(n)
    int findKthPositive(vector<int>& arr, int k) {
        if (k < arr[0]) return k;
        int n = arr.size();
        int missing = arr[0] - 1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] + 1 != arr[i + 1]) {
                missing += arr[i + 1] - arr[i] - 1;
                if (missing >= k) {
                    return arr[i+1] - (missing - k) - 1;
                }
            }
        }

        return arr[n - 1] + (k - missing);
    }

    // binary search
    // O(lgn)
    int findKthPositive(vector<int>& arr, int k) {
        if (k < arr[0]) return k;

        int l = 0, r = arr.size(), m = 0;
        while (l < r) {
            m = (l + r) / 2;
            // the number of missing under A[m] is A[m] - m - 1
            if (arr[m] - m - 1 < k) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        
        return l + k;
    }
};