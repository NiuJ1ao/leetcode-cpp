#include <unordered_map>
using namespace std;

/* 
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
*/

class Solution {
public:
    int tribonacci(int n) {
        unordered_map<int, int> m;
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                m[i] = 0;
            } else if (i == 1 || i == 2) {
                m[i] = 1; 
            } else {
                m[i] = m[i-1] + m[i-2] + m[i-3]; 
            }
        }
        return m[n];
    }

    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        int res = 1, prev = 1, prev1 = 0;
        while (n > 2) {
            int tmp = res;
            res = res + prev + prev1;
            int tmp1 = prev;
            prev = tmp;
            prev1 = tmp1;
            n--;
        }
        return res;
    }
};