#include <vector>
using namespace std;

/*
You may recall that an array arr is a mountain array if and only if:
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.
*/

class MountainArray {
    vector<int> v;
    public:
        int get(int index) {return v[index];};
        int length() {return v.size();};
};

class Solution {
public:
    // Binary search
    // Improvement: it is ok to avoid binary search for peak. But the logic is too complex and code is hard to read.
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l, r, m, peak = 0;

        // find peak
        l = 0;
        r = n - 1;
        while (l < r) {
            m = (l + r) / 2;
            if (mountainArr.get(m) < mountainArr.get(m + 1)) {
                l = peak = m + 1;
            } else {
                r = m;
            }
        }

        // find target in the left of peak
        l = 0;
        r = peak;
        while (l <= r) {
            m = (l + r) / 2;
            if (mountainArr.get(m) < target) {
                l = m + 1;
            } else if (mountainArr.get(m) > target) {
                r = m - 1;
            } else {
                return m;
            }
        }

        // find target in the right of peak
        l = peak;
        r = n - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (mountainArr.get(m) > target) {
                l = m + 1;
            } else if (mountainArr.get(m) < target) {
                r = m - 1;
            } else {
                return m;
            } 
        }
        return -1;
    }
};