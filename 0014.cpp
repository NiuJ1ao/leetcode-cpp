#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* 
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    // sort -> compare first & last
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0], last = strs[strs.size() - 1];
        for (int i = 0; i < min(first.length(), last.length()); i++) {
            if (first[i] != last[i]) return res;
            res += first[i];
        }
        return res;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int i = 0;
        while (true) {
            bool match = true;
            if (i == strs[0].size()) return res;
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].size()) return res;
                match = match && (c == strs[j][i]);
                if (!match) return res;
            }
            res += c;
            i++;
        }
        return res;
    }
};