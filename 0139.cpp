#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

class Solution {
public:
    // DP optimized
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

    // DP dummy
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = words.count(string(1, s[i])) == 1;
            for (int j = i; j < n; j++) {
                for (int k = i; k < j; k++) {
                    dp[i][j] = words.count(s.substr(i, j - i + 1)) == 1 || (dp[i][k] && dp[k+1][j]);
                    if (dp[i][j]) break;
                }
            }
        }

        return dp[0][n-1];
    }

    // brute-force
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> visited;
        return helper(s, words, visited);
    }

    bool helper(string s, unordered_set<string>& words, unordered_map<string, bool>& visited) {
        // cout << s << endl;
        if (visited.count(s)) return visited[s];
        if (words.count(s)) return true;

        int n = s.length();
        visited[s] = false;
        for (int i = 1; i <= n; i++) {
            visited[s] = helper(s.substr(0, i), words, visited) && helper(s.substr(i, n-i), words, visited);
            if (visited[s]) return true;
        }

        return visited[s];
    }
};