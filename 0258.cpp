/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/

class Solution {
public:
    // https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }

    int addDigits(int num) {
        while (num > 9) {
            int res = 0;
            while (num) {
                res += num % 10;
                num /= 10;
            }
            num = res;
        }
        return num;
    }

    int addDigits(int num) {
        if (num < 10) return num;
        int res = 0;
        while (num) {
            res += num % 10;
            num /= 10;
        }
        return addDigits(res);
    }
};