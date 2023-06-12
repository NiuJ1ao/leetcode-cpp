#include <string>
using namespace std;

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        string lowerS = "";
        for (char c: s) {
            if (isalnum(c)) {
                lowerS += tolower(c);
            }
        }

        int l = 0, r = lowerS.length() - 1;
        while (l < r) {
            if (lowerS[l++] != lowerS[r--]) return false;
        }

        return true;
    }

    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (!isalnum(s[i]) && i < j) i++;
            while (!isalnum(s[j]) && i < j) j--;
            if (toupper(s[i]) != toupper(s[j])) return false;
        }
        
        return true;
    }
};