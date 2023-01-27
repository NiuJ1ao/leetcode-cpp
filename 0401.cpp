#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.
Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.
*/

class Solution {
public:
    // Hamming weight
    int countOnes(int x) {
        x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
        x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
        x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
        x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
        x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));
        return x;
    }

    // solution 1 - count ones in decimals
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        if (turnedOn > 8) return res;

        unordered_map<int, int> memo;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (memo.find(i) == memo.end()) memo[i] = countOnes(i);
                if (memo.find(j) == memo.end()) memo[j] = countOnes(j);
                if (memo[i] + memo[j] == turnedOn) {
                    string time = to_string(i);
                    if (j < 10) {
                        time += ":0" + to_string(j);
                    } else {
                        time += ":" + to_string(j);
                    }
                    res.push_back(time);
                }
            }
        }

        return res;
    }

    // solution 2 - print table (this is helper function).
    // iterate all possible indices with target size.
    // using stack and recursion.
    void printTable(int target, int index, vector<int> c) {
        if (target == 0) {
            for (int i = 0; i < c.size(); i++) {
                printf("%d ", c[i]);
            }
            printf("\n");
            return;
        }
        for (int i = index; i < 6; i++) {
            c.push_back(i);
            printTable(target-1, i+1, c);
            c.pop_back();
        }
    }
};