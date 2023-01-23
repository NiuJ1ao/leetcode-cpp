#include <limits.h>

// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
// Difficulty: how to handle INT_MIN and INT_MAX.

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int digit = x % 10;
            x = (x - digit) / 10;

            if (INT_MIN / 10 > res || res > INT_MAX / 10) {
                return 0;
            }
            res *= 10;
            if ((res == INT_MAX - 7 && digit > 7) || (res == INT_MIN + 8 && digit < -8)) {
                return 0;
            } 
            res += digit;
        }

        return res;
    }
};