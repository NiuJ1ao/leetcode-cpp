#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

/*
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
*/

class Solution {
public:
    // DP
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> dp;
        return helper(dp, s1, s2);
    }

    bool helper(unordered_map<string, bool>& dp, string s1, string s2) {
        int n = s1.length();
        if (n == 1) return s1 == s2;

        string key = s1 + s2;
        if (dp.count(key)) return dp[key];

        bool res;
        if (s1 == s2) {
            res = true;
        } else {
            res = false;
            for (int i = 1; i < n && !res; i++) {
                res = res || helper(dp, s1.substr(0, i), s2.substr(0, i)) && helper(dp, s1.substr(i), s2.substr(i));
                res = res || helper(dp, s1.substr(0, i), s2.substr(n-i, i)) && helper(dp, s1.substr(i, n-i), s2.substr(0, n-i));
            }
            dp[key] = res;
        }

        return res;
    }

    /*
    Cache: 1-d array that stores the result of substring s1 & s2,
    the value can be either 0 (no computed yet), 1 (valid), 2 (invalid).
    */
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> dp;
        int n = s1.length();
        vector<char> cache((n + 1) * n * n, 0);
        return helper(s1, s2, 0, 0, n, cache);
    }

    bool helper(string s1, string s2, int idx1, int idx2, int n, vector<char>& cache) {
        int m = s1.length();
        vector<int> freq(26, 0);
        int zero_count = 0;

        int cacheIdx = (n * m + idx1) * m + idx2;
        if (cache[cacheIdx])
            return cache[cacheIdx] == 1;

        // count the frequency of char in substrings.
        for (int i = 0; i < n; i++) {
            zero_count += (0 == freq[s1[idx1 + i] - 'a']) - (0 == ++freq[s1[idx1 + i] - 'a']);
            zero_count += (0 == freq[s2[idx2 + i] - 'a']) - (0 == --freq[s2[idx2 + i] - 'a']);
        }

        // if two substrings have different characters
        if (zero_count) {
            cache[cacheIdx] = 2;
            return false;
        }

        // if length == 1, return true
        if (n == 1) {
            cache[cacheIdx] = 1;
            return true;
        }

        // recursively check all possible split positions
        bool res = false;
        for (int i = 1; i < n && !res; i++) {
            res = res || helper(s1, s2, idx1, idx2, i, cache) && helper(s1, s2, idx1 + i, idx2 + i, n - i, cache);
            res = res || helper(s1, s2, idx1 + n - i, idx2, i, cache) && helper(s1, s2, idx1, idx2 + i, n - i, cache);
        }

        cache[cacheIdx] = res ? 1 : 2;
        return res;
    }
};