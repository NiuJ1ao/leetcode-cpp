#include <vector>
#include <string>
#include <limits.h>
#include <iostream>
using namespace std;

/*
You are given a string of digits num, such as "123456579". We can split it into a Fibonacci-like sequence [123, 456, 579].
*/

class Solution {
public:
    bool isOverflow(string num) {
        // prune num >= 2^31
        if (num.length() > 10) 
            return true;
        if (num.length() == 10) {
            int pre = stoi(num.substr(0, 9));
            int back = int(num.back()) - 48;
            if (pre > 214748364 || (pre == 214748364 && back > 7)) 
                return true;
        }
        return false;
    }

    vector<int> splitIntoFibonacci(string num) {
        vector<int> res;
        int N = num.size();

        // store possible nums in 2d array.
        vector<vector<int>> nums(N);
        for (int i = 0; i < N; i++) {
            if (num[i] == '0')  {
                nums[i].push_back(0);
                continue;
            }
            for (int len = 1; len <= N - i; len++) {
                string sub = num.substr(i, len);
                if (isOverflow(sub)) break;
                nums[i].push_back(stoi(sub));
            }
        }

        // iterate nums according to the number of digits.
        for (int i = 0; i < nums[0].size(); i++) {
            int first = nums[0][i];
            if (i + 1 == nums.size()) break;
            for (int j = 0; j < nums[i+1].size(); j++) {
                int second = nums[i+1][j];
                if (helper(nums, first, second, i+j+2, &res)) {
                    return res;
                }
            }
        }

        return res;
    }

    bool helper(vector<vector<int>> nums, int x1, int x2, int idx, vector<int>* res) {
        if (idx == nums.size()) {
            if ((*res).size() > 0) {
                (*res).push_back(x1);
                (*res).push_back(x2);
                return true;
            } else {
                return false;
            }
        }

        bool isComplete = false;
        for (int i = 0; i < nums[idx].size(); i++) {
            if (INT_MAX - x2 < x1) break;
            if (x1 + x2 == nums[idx][i]) {
                (*res).push_back(x1);
                isComplete = helper(nums, x2, nums[idx][i], idx+i+1, res);
            }
        }

        if ((*res).size() > 0 && !isComplete) {
            (*res).pop_back();
        }

        return isComplete;
    }


    // same logic, simpler code
    vector<int> splitIntoFibonacci(string num) {
        vector<int> res;
        helper(num, 0, res);
        return res;
    }

    bool helper(string s, int idx, vector<int>& res) {
        if (idx == s.length() && res.size() > 2) {
            return true;
        }
        for (int i = idx; i < s.length(); i++) {
            // no leading zero
            if (s[idx] == '0' && i > idx) {
                break;
            }

            // prune num > 2^31
            string sub = s.substr(idx, i-idx+1);
            if (isOverflow(sub)) break;
            int num = stoi(sub);

            int n = res.size();
            // early termination - num is larger than the sum of two prev.
            if (n >= 2 && (INT_MAX - res[n-1] < res[n-2] || num > res[n-1] + res[n-2]))
                break;

            if (n <= 1 || num == res[n-1] + res[n-2]) {
                res.push_back(num);
                if (helper(s, i+1, res)) {
                    return true;
                }
                res.pop_back();
            }
        }

        return false;
    }
};