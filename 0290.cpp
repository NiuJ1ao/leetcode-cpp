#include <string>
#include <unordered_map>
using namespace std;

/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        istringstream in(s);
        int i = 0, n = pattern.length();
        for (string word; in >> word; i++) {
            if (i == n || p2i[pattern[i]] != w2i[word]) return false;
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return i == n;
    }
};