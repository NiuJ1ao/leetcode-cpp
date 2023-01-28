#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if (s == t) return 1;
        int N = s.length();
        int M = t.length();
        if (N < M) return 0;

        vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

        // base case: 
        // when i == N, dp[N][j] = 0
        // when j == M, dp[i][M] = 1 - empty string is subsequence for any string
        for (auto& r: dp) {
            r[M] = 1;
        }

        // DP: # subsequence of s[i:] == t[j:]
        // e.g. s = bgbag, t = bag 
        for (int i = N - 1; i >= 0; i--) {
            for (int j = M - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    // 1: s[i] matches t[j]  -> take # subsequence of s[i+1:] == t[j+1:] (s[i]=t[j]=b, s=gb[ag], t=ag)
                    // 2: s[i] !matches t[j] -> take # subsequence of s[i+1:] == t[j:] (s[i]=t[j]=b, s=g[bag], t=[bag])
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j]; 
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }

        return dp[0][0];
    }

    // Compressed DP: optimize space complexity to O(N)
    int numDistinct(string s, string t) {
        // int n = s.length(), m = t.length();
        // vector<int>dp(m+1, 0);
        // dp[0] = 1;
        // for(int i = 1; i <= n; i++) {
        //     for(int j = m; j > 0; j--) {
        //         if(s[i-1] == t[j-1]) dp[j] = dp[j-1] + dp[j];
        //     }
        // }
        // return dp[m];

        int N = s.length();
        int M = t.length();
        vector<int> dp(N + 1);
        for (int j = 0; j < M; j++) {
            int prev = 0;
            for (int i = 0; i < N; i++) {
                if (j == 0) {
                    prev = 1; // base case
                }
                int val = dp[j+1];
                if (t[j] == s[i]) {
                    dp[j + 1] = dp[j] + prev;
                } else {
                    dp[j + 1] = dp[j];
                }
                prev = val;
            }
        }
        return dp[N];
    }
};