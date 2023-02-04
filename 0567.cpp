#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
*/

class Solution {
public:
    // TLE
    bool checkInclusion(string s1, string s2) {
        int i = 0;
        int m = s1.length(), n = s2.length();
        unordered_map<char, int> lookup;

        if (m > n) return false;

        for (char c: s1) {
            ++lookup[c];
        }

        for (int j = 0; j <= n - m; j++) {
            int checked = helper(s2, j, j + m, lookup);
            if (checked == j + m) return true;
        }

        return false;
    }

    int helper(string& s, int idx, int target, unordered_map<char, int> lookup) {
        if (idx == target) {
            return idx;
        }

        int checked = idx;
        if (lookup.count(s[idx]) && lookup[s[idx]] > 0) {
            lookup[s[idx]]--;
            checked = helper(s, idx+1, target, lookup);
            lookup[s[idx]]++;
        }

        return checked;
    }

    // sliding window optimized
    bool checkInclusion(string s1, string s2) {
        int i = 0;
        int m = s1.length(), n = s2.length();
        if (m > n) {
            return false;
        }

        vector<int> s1map(26, 0), s2map(26, 0);
        for (int i = 0; i < m; i++) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (s1map[i] == s2map[i]) 
                count++;
        }

        for (int i = 0; i < n - m; i++) {
            int r = s2[i + m] - 'a', l = s2[i] - 'a';
            if (count == 26) 
                return true;

            /*
            When we slide the window, if the deduction of the last element and the addition of the new element 
            leads to a new frequency match of any of the characters, we increment the count by 1. 
            If not, we keep the count intact. But, if a character whose frequency was the same earlier
            (prior to addition and removal) is added, it now leads to a frequency mismatch which is taken into 
            account by decrementing the same count variable.
            */
            s2map[r]++;
            if (s2map[r] == s1map[r]) {
                count++;
            } else if (s2map[r] == s1map[r] + 1) {
                count--;
            }

            s2map[l]--;
            if (s2map[l] == s1map[l]) {
                count++;
            } else if (s2map[l] == s1map[l] - 1) {
                count--;
            }
        }

        // s1map == s2map
        return count == 26;
    }
};