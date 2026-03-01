#include <string>
#include <vector>
using namespace std;

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26);
        int count = 0;
        for (char c: s) {
            freq[c-'a']++;
            count++;
        }

        for (char c: t) {
            if (--freq[c-'a'] < 0) return false;
            count--;
        }

        return count==0;
    }
};