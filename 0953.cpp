#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

/* 
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.
*/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        bool res = true;
        unordered_map<char, int> mp;
        for (int i = 0; i < order.length(); i++) {
            mp[order[i]] = i + 1;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int idx = 0;
            while (idx < w1.length() && idx < w2.length()) {
                int val1 = mp[w1[idx]];
                int val2 = mp[w2[idx]];
                if (val1 == val2) {
                    idx++;
                } else if (val1 < val2) {
                    break;
                } else {
                    return false;
                }
            }
            if (idx < w1.length() && idx == w2.length()) {
                return false;
            }
        }
        
        return res;
    }

    // Build a transform mapping from order,
    // Find all alien words with letters in normal order.
    bool isAlienSorted(vector<string> words, string order) {
        int mapping[26];
        for (int i = 0; i < 26; i++)
            mapping[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w)
                c = mapping[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
};