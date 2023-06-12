#include <string>
#include <vector>
using namespace std;

/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
*/

class Solution {
public:
    // backtracking
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> step;
        helper(s, res, step, 0);
        return res;
    }

    void helper(string& s, vector<vector<string>>& res, vector<string>& step, int idx) {
        if (idx == s.length()) {
            res.push_back(step);
        } else {
            for (int i = idx; i < s.length(); i++) {
                if (isPalindrome(s, idx, i)) {
                    step.push_back(s.substr(idx, i -idx + 1));
                    helper(s, res, step, i + 1);
                    step.pop_back();
                }
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};