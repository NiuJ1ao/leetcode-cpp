#include <string>
#include <vector>
#include <climits>
using namespace std;

/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        vector<int> mp(128, 0);

        for (char c: t)
            mp[c]++;

        int l = 0, r = 0;
        int count = n, head = 0, len = INT_MAX;
        while (r < m) {
            if (mp[s[r++]]-- > 0) count--;
            while (count == 0) {
                if (r - l < len) {
                    head = l;
                    len = r - head;
                }
                if (mp[s[l++]]++ == 0) count++;
            }
        }

        return len == INT_MAX ? "" : s.substr(head, len);
    }
};