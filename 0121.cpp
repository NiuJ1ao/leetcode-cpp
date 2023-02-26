#include <vector>
#include <climits>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minp = INT_MAX; // minimum price so far.
        for (int i = 0; i < prices.size(); i++) {
            minp = min(minp, prices[i]);
            res = max(res, prices[i] - minp);
        }
        return res;
    }
};