#include <vector>
using namespace std;

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

class Solution {
public:
    // merge sort
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res = 0;

        vector<int> sortedNums;

        int idx1 = 0, idx2 = 0;
        int lenNums1 = nums1.size(), lenNums2 = nums2.size();

        // merge in merge sort
        while (idx1 < lenNums1 && idx2 < lenNums2) {
            if (nums1[idx1] < nums2[idx2]) {
                sortedNums.push_back(nums1[idx1]);
                idx1++;
            } else {
                sortedNums.push_back(nums2[idx2]);
                idx2++;
            }
        }

        // append the rest
        while (idx1 < lenNums1) {
            sortedNums.push_back(nums1[idx1]);
            idx1++;
        }
        while (idx2 < lenNums2) {
            sortedNums.push_back(nums2[idx2]);
            idx2++;
        }

        int len = sortedNums.size();
        if (len % 2 == 0) {
            int meidanIdx = len / 2;
            res = 0.5 * (sortedNums[meidanIdx-1] + sortedNums[meidanIdx]);
        } else {
            res = sortedNums[(int) len/2];
        }

        return res;
    }

    // terminate when locate the median
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res = 0;
        int lenNums1 = nums1.size(), lenNums2 = nums2.size();
        int totalNums = lenNums1 + lenNums2;
        int medianIdx = totalNums / 2;;
        bool isEven = totalNums % 2 == 0;
        medianIdx += !isEven;

        int idx1 = 0, idx2 = 0;
        while (idx1 < lenNums1 && idx2 < lenNums2 && idx1 + idx2 < medianIdx) {
            if (nums1[idx1] < nums2[idx2]) {
                res = nums1[idx1];
                idx1++;
            } else {
                res = nums2[idx2];
                idx2++;
            }
        }

        // if array is too short
        while (idx1 < lenNums1 && idx1 + idx2 < medianIdx) {
            res = nums1[idx1];
            idx1++;
        }
        while (idx2 < lenNums2 && idx1 + idx2 < medianIdx) {
            res = nums2[idx2];
            idx2++;
        }

        if (isEven) {
            if (idx1 == lenNums1) {
                res += nums2[idx2];
            } else if (idx2 == lenNums2) {
                res += nums1[idx1];
            } else {
                res += min(nums1[idx1], nums2[idx2]);
            }
            res /= 2;
        }

        return res;
    }
};