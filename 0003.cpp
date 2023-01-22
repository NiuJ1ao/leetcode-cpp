#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lenS = s.length();
        if (lenS == 1 || lenS == 0) {
            return lenS;
        }
        int start = 0, len = 1;
        int longest = len;
        string subS = s.substr(start, len);

        for (int i = 1; i < lenS; i++) {
            if (subS.find(s[i]) == -1) {
                // no repeat char
                len++;
                longest = max(len, longest);
            } else {
                // find repeat char
                start++;
                i = start;
                len = 1;
            }
            subS = s.substr(start, len);
        }

        return longest;
    }

    // sliding window
    // count the frequency of chars
    int lengthOfLongestSubstring(string s) {
        int lenS = s.length();
        if (lenS == 1 || lenS == 0) {
            return lenS;
        }

        int start = 0, end = 1;
        int res = 1;
        unordered_map<char, int> m;
        while (end < lenS + 1) {
            char i = s[end-1];
            m[i]++;

            while (m[i] > 1) {
                char j = s[start];
                m[j]--;
                start++;
            }

            res = max(res, end - start);
            end++;
        }

        return res;
    }

    // sliding window optimized
    // store the next indices of chars
    int lengthOfLongestSubstring(string s) {
        int lenS = s.length();
        if (lenS == 1 || lenS == 0) {
            return lenS;
        }

        int start = 0, end = 1;
        int res = 1;
        unordered_map<char, int> m;
        while (end < lenS + 1) {
            int last = end - 1;
            if (m[s[last]] > 0) {
                start = max(m[s[last]], start);
            }
            m[s[last]] = end;
            res = max(res, end - start);
            end++;
        }

        return res;
    }

    // bit map
    int lengthOfLongestSubstring(string s) {
        int lenS = s.length();
        if (lenS == 1 || lenS == 0) {
            return lenS;
        }

        int start, end, res = 0;
        unordered_set<char> bitSet;
        while (end < lenS) {
            if (bitSet.find(s[end]) == bitSet.end()) {
                // not found - store it
                bitSet.insert(s[end]);
                end++;
            } else {
                // found - delete it and shift start
                bitSet.erase(s[start]);
                start++;
            }
            res = max(res, end - start);
        }

        return res;
    }
};