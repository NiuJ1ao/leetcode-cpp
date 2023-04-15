#include <vector>
#include <functional>
using namespace std;

/*
There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.
*/

class Solution {
public:
    // DP
    // dp[i,k] means picking k elements from pile[i] to pile[n-1].
    // We can pick 0,1,2,3... elements from the current pile[i] one by one.
    // we return max of all the options.
    int maxValueOfCoins(vector<vector<int>>& A, int K) {
        int n = A.size();
        vector<vector<int>> memo(n + 1, vector<int>(K + 1, 0));
        function<int(int, int)> dp = [&](int i, int k) {
            if (memo[i][k] > 0) return memo[i][k];
            if (i == n || k == 0) return 0;
            int res = dp(i + 1, k), cur = 0;
            for (int j = 0; j < A[i].size() && j < k; ++j) {
                cur += A[i][j];
                res = max(res, dp(i + 1, k - j - 1) + cur);
            }
            memo[i][k] = res;
            return res;
        };
        return dp(0, K);
    }
};