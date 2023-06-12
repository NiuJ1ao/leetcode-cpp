#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
*/

class Solution {
public:
    // space complexity: O(1)
    string reverseWords(string s) {
        // reverse the whole string
        reverse(s.begin(), s.end());
        int l = 0, r = 0, i = 0, n = s.length();
        while (i < n) {
            // fill a word without space
            while (i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }

            if (l < r) {
                // reverse current word
                reverse(s.begin() + l, s.begin() + r);
                if (r == n) break;
                
                // add delimieter
                s[r++] = ' ';
                l = r;
            }
            i++;
        }
        // remove last spaces if any
        if (r > 0 && s[r-1] == ' ') r--;

        // resize string
        s.resize(r);
        return s;
    }

    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' '){
                words.push_back(word);
                word = "";
            } else {
                word.push_back(s[i]);
            }
        }

        if (word.length() > 0) {
            words.push_back(word);
        }

        string res = "", delimiter = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            if (words[i] != ""){
                res += delimiter + words[i];
                delimiter = " ";
            }
        }
        return res;
    }
};