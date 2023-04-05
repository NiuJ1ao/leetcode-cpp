#include <vector>
#include <algorithm>
using namespace std;

/*
You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.
*/

class Solution {
public:
    // sort + binary search
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        int l, r, idx;
        long long product;
        vector<int> pairs(n, 0);
        for (int i = 0; i < n; i++) {
            l = 0;
            r = m;
           
            while (l < r) {
                idx = (l + r) / 2;
                product = (long long) spells[i] * (long long) potions[idx];
                if (product >= success) {
                    r = idx;
                } else {
                    l = idx + 1;
                }
            }

            pairs[i] = m - l;
        }

        return pairs;
    }

    // shorter version
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (int a: spells) {
            long need = (success + a - 1) / a;
            auto it = lower_bound(potions.begin(), potions.end(), need);
            res.push_back(potions.end() - it);
        }
        return res;
    }
};