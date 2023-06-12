#include <string>
using namespace std;

/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        while (s.back() == ' ') {
            s.pop_back();
        }

        while (!s.empty() && s.back() != ' ') {
            res++;
            s.pop_back();
        }
        return res;
    }
};