#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> v1(256, -1), v2(256, -1); // 256 ASCII code space
        for (int i = 0; i < s.length(); i++) {
            if (v1[s[i]] != v2[t[i]]) return false;
            v1[s[i]] = i;
            v2[t[i]] = i;
        }
        return true;
    }

    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t, t2s;
        for (int i = 0; i < s.length(); i++) {
            if (s2t.count(s[i]) && t[i] != s2t[s[i]]) return false;
            if (t2s.count(t[i]) && s[i] != t2s[t[i]]) return false;
            
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }
        return true;
    }
};