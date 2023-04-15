#include <string>
#include <vector>
using namespace std;

/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
*/

class Solution {
public:
    // DP
    // If s[l] == s[r] then dp[l][r] = dp[l+1][r-1] + 2
    // Else dp[l][r] = max(dp[l+1][r], dp[l][r-1])
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }

    // DP - space optimized
    // Since we need to access up to 2 dp states: current dp state and previous dp state.
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n, 0), dpPrev(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i+1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[j] = dpPrev[j-1] + 2;
                } else {
                    dp[j] = max(dpPrev[j], dp[j-1]);
                }
            }
            dp.swap(dpPrev);
        }
        return dpPrev[n-1];
    }
};