/*
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 1 && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }

    // 1162261467 is largest 3^x in int32
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};