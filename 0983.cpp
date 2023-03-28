#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

/*
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.
*/

class Solution {
public:
    // DP
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        queue<pair<int, int>> last7, last30;
        int cost = 0;
        for (int d: days) {
            // 7/30-day expire
            while (!last7.empty() && last7.front().first + 7 <= d) last7.pop();
            while (!last30.empty() && last30.front().first + 30 <= d) last30.pop();
            last7.push({d, cost + costs[1]});
            last30.push({d, cost + costs[2]});
            cost = min3(cost + costs[0], last7.front().second, last30.front().second);
        }
        return cost;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel(begin(days), end(days));
        vector<int> dp(366);
        for (int i = 1; i <= 365; i++) {
            if (!travel.count(i)) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = min3(dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]);
            }
        }

        return dp[365];
    }

    int min3(int a, int b, int c) {
        return min(a, min(b, c));
    }
};