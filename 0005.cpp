#include <string>
using namespace std;

// Given a string s, return the longest palindromic substring in s.
// A string is palindromic if it reads the same forward and backward.

class Solution {
public:
    // brute force
    string longestPalindrome(string s) {
        string res = "";
        int lenRes = res.length();
        int lenS = s.length();
        for (int i = 0; i < lenS; i++) {
            for (int j = i; j < lenS; j++) {
                string subS = s.substr(i, j - i + 1);
                int lenSubS = subS.length();
                if (lenSubS > lenRes) {
                    bool isPalindromic = true;
                    for (int si = 0; si < lenSubS / 2; si++) {
                        isPalindromic = isPalindromic && subS[si] == subS[lenSubS - si - 1];
                    }
                    if (isPalindromic) {
                        res = subS;
                        lenRes = lenSubS;
                    }
                }
            }
        }
        return res;
    }

    // DP: when a string is palindrome, its substring ([i+1][j-1]) must be palindrome.
    string longestPalindrome(string s) {
        string res = "";
        int length = s.length();
        bool dp[length][length];

        for (int i = length - 1; i >= 0; i--) {
            for (int j = i; j < length; j++) {
                dp[i][j] = (s[i] == s[j]) && (j - i < 3 || dp[i+1][j-1]); // edge chars are equal, and substr is palindrome
                if (dp[i][j] && (j - i + 1 > res.length())) {
                    res = s.substr(i, j - i + 1);
                }
            }
        }

        return res;
    }

    // expand around center: a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2n−1 such centers.
    // 2n-1? The reason is the center of a palindrome can be in between two letters.
    string longestPalindrome(string s) {
        int lenS = s.length();
        if (lenS < 2) {
            return s;
        }

        int start = 0, end = 0;
        for (int i = 0; i < lenS; i++) {
            int len1 = expandAroundCenter(s, i, i, lenS); // odd
            int len2 = expandAroundCenter(s, i, i + 1, lenS); //even
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(string s, int left, int right, int length) {
        int l = left;
        int r = right;
        while (l >= 0 && r < length && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    } 

    // sliding window: optimized version of expand around center
    // avoid asymmetric centers.
    string longestPalindrome(string s) {
        int lenS = s.length();
        if (lenS < 2) {
            return s;
        }

        int left = 0, right = -1;
        int pl = 0, pr = 0;
        while (left < lenS) {
            // shift right if duplicate chars (e.g., bbb)
            while (right + 1 < lenS && s[left] == s[right+1]) {
                right++;
            }
            // expand around center
            while (left - 1 >= 0 && right + 1 < lenS && s[left-1] == s[right+1]) {
                left--;
                right++;
            }
            if (right - left > pr - pl) {
                pl = left;
                pr = right;
            }

            // reset to the next center
            left = (left + right) / 2 + 1;
            right = left;
        }
        return s.substr(pl, pr - pl + 1);
    }

    // Manacher's algorithm
};