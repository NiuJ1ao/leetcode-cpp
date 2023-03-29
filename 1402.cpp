#include <vector>
#include <algorithm>
using namespace std;

/*
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
*/

class Solution {
public:
    // DP
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j == i) {
                    dp[i][j] = satisfaction[i];
                } else {
                    int time = j - i + 1;
                    dp[i][j] = dp[i][j - 1] + satisfaction[j] * time;
                }
                if (j == n - 1)
                    res = max(res, dp[i][j]);
            }
        }

        return res;
    }

    // We choose dishes from most satisfied.
    // Everytime we add a new dish to the menu list,
    // all dishes on the menu list will be cooked one time unit later,
    // so the result += total satisfaction on the list.
    // We'll keep doing this as long as A[i] + total > 0.
    // (change i * s[i] to (\sum_{n=0}^{i} s[i]))
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();
        int res = 0, total = 0;

        for (int i = n - 1; i >= 0 && satisfaction[i] > -total; i--) {
            total += satisfaction[i];
            res += total;
        }

        return res;
    }
};