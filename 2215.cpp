#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

/*
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.
*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v1, v2;
        set<int> s1(begin(nums1), end(nums1)), s2(begin(nums2), end(nums2));
        set_difference(begin(s1), end(s1), begin(s2), end(s2), back_inserter(v1));
        set_difference(begin(s2), end(s2), begin(s1), end(s1), back_inserter(v2));
        return {v1, v2};
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);

        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        for (int i: s1) {
            if (!s2.count(i)) res[0].push_back(i);
        }

        for (int i: s2) {
            if (!s1.count(i)) res[1].push_back(i);
        }

        return res;
    }
};