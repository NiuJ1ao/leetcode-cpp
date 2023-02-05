#include <vector>
#include <string>
using namespace std;

/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Same as 567.
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int m = p.length(), n = s.length();
        if (m > n) {
            return res;
        }

        vector<int> pmap(26, 0), smap(26, 0);
        for (int i = 0; i < m; i++) {
            pmap[p[i] - 'a']++;
            smap[s[i] - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (pmap[i] == smap[i]) 
                count++;
        }

        int i = 0;
        while (i < n - m) {
            int r = s[i + m] - 'a', l = s[i] - 'a';
            if (count == 26) 
                res.push_back(i);

            /*
            When we slide the window, if the deduction of the last element and the addition of the new element 
            leads to a new frequency match of any of the characters, we increment the count by 1. 
            If not, we keep the count intact. But, if a character whose frequency was the same earlier
            (prior to addition and removal) is added, it now leads to a frequency mismatch which is taken into 
            account by decrementing the same count variable.
            */
            smap[r]++;
            if (smap[r] == pmap[r]) {
                count++;
            } else if (smap[r] == pmap[r] + 1) {
                count--;
            }

            smap[l]--;
            if (smap[l] == pmap[l]) {
                count++;
            } else if (smap[l] == pmap[l] - 1) {
                count--;
            }

            i++;
        }

        if (count == 26) 
            res.push_back(i);
        return res;
    }
};