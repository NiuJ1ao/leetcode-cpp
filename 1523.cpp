#include <cmath>
using namespace std;

/*
Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
*/

class Solution {
public:
    int countOdds(int low, int high) {
        int res = ceil((high - low) * 0.5);
        if (high % 2 == 1 && low % 2 == 1) res++;
        return res;
    }
};