#include <vector>
using namespace std;

/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = -2, res = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i]) {
                res += 0.5 * (i - l) - 1;
                l = i;
            }
        }
        res += (flowerbed.size() + 1 - l) * 0.5 - 1;
        return res >= n;
    }
};