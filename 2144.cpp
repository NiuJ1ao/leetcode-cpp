#include <vector>
#include <algorithm>
using namespace std;

/*
A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.

The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.

For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies.
*/

// similar to 0561
class Solution {
public:
    // sorting
    int minimumCost(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, n = A.size();
        for (int i = 0; i < A.size(); ++i)
            if (i % 3 != n % 3)
                res += A[i];
        return res;
    }

    // counting sort
    int minimumCost(vector<int>& cost) {
        const int k = 100;
        int freq[k+1] = {0};

        for (int c: cost) {
            freq[c]++;
        }

        int isBuy = 2;
        int res = 0;
        for (int i = 100; i >= 0; i--) {
            while (freq[i]) {
                if (isBuy) {
                    res += i;
                    isBuy--;
                } else {
                    isBuy = 2;
                }
                freq[i]--;
            }
        }
        return res;
    }
};