/*
Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3^x.
*/

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int prevSub = 0;
        while (n > 2) {
            int sub = 1;
            int tmp = n;
            while (tmp > 2) {
                tmp /= 3;
                sub *= 3;
            }
            if (sub == prevSub) return false;
            n -= sub;
            prevSub = sub;
        }

        return n != 2;
    }
};