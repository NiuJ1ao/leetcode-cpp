#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // DP
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());

        for (auto w: words) {
            int len = w.length();
            vector<bool> dp(len + 1);
            dp[0] = true; //base case
            for (int i = 1; i < len + 1; i++) {
                for (int j = i == len; j < i; j++) { // Note: There is an corner case, when i == length, since we don't want to use the word itself directly, we should check 1 <= j < i instead.
                    if (dp[i]) break;
                    dp[i] = dp[j] && dict.count(w.substr(j, i - j));
                }
            }
            if (dp[len]) {
                res.push_back(w);
            }
        }

        return res;
    }


    // greedy: TLE error
    vector<string> findAllConcatenatedWordsInADict1(vector<string>& words) {
        vector<string> res;
        int shortestWord = 30;
        unordered_map<int, vector<string>> lenMap;
        for (auto w: words) {
            int len = w.length();
            if (len < shortestWord) shortestWord = len;
            lenMap[len].push_back(w);
        }

        for (auto w: words) {
            bool isConcate = isConcatenated(w.length(), w, words, lenMap, shortestWord);
            if (isConcate) res.push_back(w);
        }
        
        return res;
    }

    bool isConcatenated(int wordLen, string word, vector<string>& words, unordered_map<int, vector<string>> &lenMap, int shortest) {
        if (word.length() < shortest) {
            return false;
        }

        vector<string> startsWith;
        for (int l = word.length(); l >= shortest; l--) {
            for (auto w: lenMap[l]) {
                if (w == word && word.length() < wordLen) return true;
                if (w != word) {
                    if (isStartsWith(word, w)) startsWith.push_back(w);
                }
            }
        }

        // recursion
        bool res = false;
        for (auto w: startsWith) {
            res = res || isConcatenated(wordLen, word.substr(w.length()), words, lenMap, shortest);
            if (res) return res;
        }

        return res;
    }

    bool isStartsWith(string txt, string pat) {
        bool res = true;
        for (int i = 0; i < pat.length(); i++) {
            if (txt[i] != pat[i]) {
                res = false;
                break;
            }
        }
        return res;
    }
};