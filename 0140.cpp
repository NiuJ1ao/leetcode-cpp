#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

class Solution {
public:
    // DP + backtrack
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<vector<string>> dp(n+1);
        dp[0].push_back("");

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if (dp[j].size() > 0 && words.count(word)) {
                    for (string& snt: dp[j]) {
                        if (snt.length() > 0)
                            dp[i].push_back(snt + " " + word);
                        else
                            dp[i].push_back(word);
                    }
                }
            }
        }

        return dp[n];
    }

    // backtrack
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> mp;
        return wordBreak1(s, words, mp);
    }

    vector<string> wordBreak1(string s, unordered_set<string>& wordDict, unordered_map<string, vector<string>>& mp) {
        if (mp.count(s)) return mp[s];
        vector<string> res;
        if (wordDict.count(s))
            res.push_back(s);

        for (int i = 1; i < s.length(); i++) {
            string word = s.substr(i);
            if (wordDict.count(word)) {
                string remain = s.substr(0, i);
                vector<string> prev = combine(word, wordBreak1(remain, wordDict, mp));
                res.insert(res.end(), prev.begin(), prev.end());
            }
        }
        mp[s] = res;
        return res;
    }

    vector<string> combine(string word, vector<string> prev){
        for(int i = 0; i < prev.size(); i++){
            prev[i] += " " + word;
        }
        return prev;
    }
};