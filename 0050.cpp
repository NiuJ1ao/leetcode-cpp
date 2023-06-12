#include <math.h>
using namespace std;

/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

class Solution {
public:
    // Binary Exponentiation using which we can calculate x^n using O log2(N) multiplications.
    // 7^8 + 7^2 + 7^1 = 7^(8+2+1) = 7^(11) [1011]
    double myPow(double x, int n) {
        if(n < 0) {
            x = 1 / x;
        }
        long num = labs(n);
        double res = 1;
        while (num != 0) {
            if (num & 1) res *= x; // only multiply when num is odd / bit is set
            x *= x;
            num >>= 1;
        }
        return res;
    }
};