/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.
*/

class Solution {
public:
    // Newton method
    int mySqrt(int x) {
        long r = x;
        while (r * r > x) {
            r = (r + x/r) / 2;
        }
        return r;
    }
};