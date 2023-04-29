#include <vector>
#include <algorithm>
using namespace std;

/*
There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.

Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 109 + 7.
*/

class Solution {
public:
    // DP
    // knapsack problem with additional check
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size(), mod = 1e9 + 7;
        // j employees are selected in the first i crime, and the total number of profitable plans where the working profit is at least k.
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
        dp[0][0][0] = 1;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= minProfit; k++) {
                    if (j < group[i-1]) {
                        // shorthanded for current crime
                        dp[i][j][k] = dp[i-1][j][k];
                    } else {
                        // current result + result from previous crime
                        dp[i][j][k] = (dp[i-1][j][k] + dp[i-1][j-group[i-1]][max(0, k - profit[i-1])]) % mod;
                    }
                }
            }
        }

        int res = 0;
        for (int j = 0; j <= n; j++) res = (res + dp[m][j][minProfit]) % mod;
        return res;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        int res = 0, mod = 1e9 + 7;
        for (int k = 0; k < group.size(); k++) {
            int g = group[k], p = profit[k];
            for (int i = minProfit; i >= 0; i--)
                for (int j = n - g; j >= 0; j--)
                    dp[min(i + p, minProfit)][j + g] = (dp[min(i + p, minProfit)][j + g] + dp[i][j]) % mod;
        }
        for (int x: dp[minProfit]) res = (res + x) % mod;
        return res;
    }
};