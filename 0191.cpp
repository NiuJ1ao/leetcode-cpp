#include <stdint.h>
using namespace std;

/*
Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
*/

class Solution {
public:
    // n & (n - 1) drops the lowest set bit.
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }

    int hammingWeight(uint32_t n) {
        n = (n & (0x55555555)) + ((n >> 1) & (0x55555555));
        n = (n & (0x33333333)) + ((n >> 2) & (0x33333333));
        n = (n & (0x0f0f0f0f)) + ((n >> 4) & (0x0f0f0f0f));
        n = (n & (0x00ff00ff)) + ((n >> 8) & (0x00ff00ff));
        n = (n & (0x0000ffff)) + ((n >> 16) & (0x0000ffff));
        return n;
    }

    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};