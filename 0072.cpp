#include <string>
#include <vector>
using namespace std;

/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/

class Solution {
public:
    int min3(int x, int y, int z) {return min(min(x, y), z);}

    // TLE: overlap cases
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if (m == 0) return n;
        if (n == 0) return m;

        if (word1[m-1] == word2[n-1])
            minDistance(word1.substr(0, m-1), word2.substr(0, n-1));
        
        return 1 + min3(
            minDistance(word1, word2.substr(0, n-1)),                   // insert
            minDistance(word1.substr(0, m-1), word2),                   // remove
            minDistance(word1.substr(0, m-1), word2.substr(0, n-1))     // replace
        );
    }

    // DP
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        // base case
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min3(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }

    // DP optimized
    // update dp[i][j] only require dp[i-1][j-1], dp[i][j-1] and dp[i-1][j].
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int prev = 0;
        vector<int> cur(n + 1, 0);
        // base case
        for (int j = 1; j <= n; j++) {
            cur[j] = j;
        }
        for (int i = 1; i <= m; i++) {
            prev = cur[0];
            cur[0] = i;
            for (int j = 1; j <= n; j++) {
                int tmp = cur[j];
                if (word1[i-1] == word2[j-1]) {
                    cur[j] = prev;
                } else {
                    cur[j] = 1 + min3(prev, cur[j-1], cur[j]);
                }
                prev = tmp;
            }
        }
        return cur[n];
    }
};