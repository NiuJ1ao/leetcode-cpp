#include <string>
#include <algorithm>
using namespace std;

/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
*/

class Solution {
public:
    // Sliding window
    int maxVowels(string s, int k) {
        int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
        int n = s.length();
        int count = 0, res = 0;

        for (int i = 0; i < n; i++) {
            count += vowels[s[i]-'a'];
            if (i >= k) count -= vowels[s[i-k]-'a'];
            res = max(res, count);
        }

        return res;
    }
};