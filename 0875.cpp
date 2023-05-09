#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/

class Solution {
public:
    // binary search
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int m = (l + r) / 2;

            int t = 0;
            for (int b: piles) {
                double tpp = (double) b / m; // time per pile
                t += ceil(tpp);
            }
            
            if (t > h) {
                // if take too long, eat faster
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;
    }
};