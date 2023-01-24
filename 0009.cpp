#include <limits.h>
using namespace std;

// Given an integer x, return true if x is a palindrome, and false otherwise.

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int rev = 0;
        int tmp = x;
        while (tmp != 0) {
            int digit = tmp % 10;
            tmp = (tmp - digit) / 10;

            // overflow detect
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) {
                return false;
            }

            rev = rev * 10 + digit;
        }

        return rev == x;
    }
};