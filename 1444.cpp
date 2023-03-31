#include <vector>
#include <string>
using namespace std;

/*
Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.
*/

static int MOD = 1e9+7;   
class Solution {
public:
    // DP + PrefixSum
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        vector<vector<int>> prefixSum(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                prefixSum[i][j] = prefixSum[i+1][j] + prefixSum[i][j+1] - prefixSum[i+1][j+1] + (pizza[i][j]=='A');
            }
        }
        return helper(pizza, k-1, 0, 0, dp, prefixSum);
    }

    int helper(vector<string>& pizza, int k, int idx1, int idx2, vector<vector<vector<int>>>& dp, vector<vector<int>>& prefixSum) {
        int n = pizza.size();
        int m = pizza[0].length();

        // computed
        if (dp[idx1][idx2][k] != -1) return dp[idx1][idx2][k];

        // no apple left
        if (prefixSum[idx1][idx2] == 0) return 0; 

        // valid way
        if (k == 0) return 1;

        dp[idx1][idx2][k] = 0;
        // horizontal cuts
        for (int i = idx1 + 1; i < n; i++) {
            if (prefixSum[idx1][idx2] - prefixSum[i][idx2] > 0)
                dp[idx1][idx2][k] = (dp[idx1][idx2][k] + helper(pizza, k - 1, i, idx2, dp, prefixSum)) % MOD;
        }
        
        // vertical cuts
        for (int j = idx2 + 1; j < m; j++) {
            if (prefixSum[idx1][idx2] - prefixSum[idx1][j] > 0)
                dp[idx1][idx2][k] = (dp[idx1][idx2][k] + helper(pizza, k - 1, idx1, j, dp, prefixSum)) % MOD;
        }
        return dp[idx1][idx2][k];
    }
};