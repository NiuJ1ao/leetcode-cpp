#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

/* 
A password is considered strong if the below conditions are all met:

It has at least 6 characters and at most 20 characters.
It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
It does not contain three repeating characters in a row (i.e., "Baaabb0" is weak, but "Baaba0" is strong).
Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.

In one step, you can:

Insert one character to password,
Delete one character from password, or
Replace one character of password with another character.
*/

class Solution {
public:
    int strongPasswordChecker(string s) {
        int deleteTarget = max(0, (int)s.length() - 20), addTarget = max(0, 6 - (int)s.length());
        int toDelete = 0, toAdd = 0, toReplace = 0, needUpper = 1, needLower = 1, needDigit = 1;
        
        ///////////////////////////////////
        // For cases of s.length() <= 20 //
        ///////////////////////////////////
        for (int l = 0, r = 0; r < s.length(); r++) {
            if (isupper(s[r])) { needUpper = 0; }               
            if (islower(s[r])) { needLower = 0; }
            if (isdigit(s[r])) { needDigit = 0; }
            
            if (r - l == 2) {                                   // if it's a three-letter window
                if (s[l] == s[l + 1] && s[l + 1] == s[r]) {     // found a three-repeating substr
                    if (toAdd < addTarget) { toAdd++, l = r; }  // insert letter to break repetition if possible
                    else { toReplace++, l = r + 1; }            // replace current word to avoid three repeating chars
                } else { l++; }                                 // keep the window with no more than 3 letters
            }
        }
        if (s.length() <= 20) { return max(addTarget + toReplace, needUpper + needLower + needDigit); }
        
        //////////////////////////////////
        // For cases of s.length() > 20 //
        //////////////////////////////////
        toReplace = 0;                                          // reset toReplace
        vector<unordered_map<int, int>> lenCnts(3);             // to record repetitions with (length % 3) == 0, 1 or 2
        for (int l = 0, r = 0, len; r <= s.length(); r++) {     // record all repetion frequencies
            if (r == s.length() || s[l] != s[r]) {
                if ((len = r - l) > 2) { lenCnts[len % 3][len]++; } // we only care about repetions with length >= 3
                l = r;
            }
        }
        
        /*
            Use deletions to minimize replacements, following below orders:
            (1) Try to delete one letter from repetitions with (length % 3) == 0. Each deletion decreases replacement by 1
            (2) Try to delete two letters from repetitions with (length % 3) == 1. Each deletion decreases repalcement by 1
            (3) Try to delete multiple of three letters from repetions with (length % 3) == 2. Each deletion (of three 
            letters) decreases repalcements by 1
        */
        for (int i = 0, numLetters, dec; i < 3; i++) {                
            for (auto it = lenCnts[i].begin(); it != lenCnts[i].end(); it++) {
                if (i < 2) {
                    numLetters = i + 1, dec = min(it->second, (deleteTarget - toDelete) / numLetters);
                    toDelete += dec * numLetters;               // dec is the number of repetitions we'll delete from
                    it->second -= dec;                          // update number of repetitions left
                    
                    // after letters deleted, it fits in the group where (length % 3) == 2
                    if (it->first - numLetters > 2) { lenCnts[2][it->first - numLetters] += dec; }   
                }
                
                // record number of replacements needed
                // note if len is the length of repetition, we need (len / 3) number of replacements
                toReplace += (it->second) * ((it->first) / 3);  
            }    
        }

        int dec = (deleteTarget - toDelete) / 3;                // try to delete multiple of three letters as many as possible
        toReplace -= dec, toDelete -= dec * 3;
        return deleteTarget + max(toReplace, needUpper + needLower + needDigit);
    }

    // DP 
    // https://leetcode.com/problems/strong-password-checker/solutions/231278/c-0ms-dp-solution-with-detailed-explanation-beats-100-on-time-and-space/?orderBy=most_votes
    int strongPasswordChecker(string s) {
        int n = s.size();
        if (!n) {
            return 6;            
        }
        
        int repeat = 1;
        int replace = 0;
        int remove = 0;
        int add = 0;
        char cur = s[0];
        int lower = islower(cur);
        int upper = isupper(cur);
        int number = isdigit(cur);

        vector<int> repeatVec;
        
        for (int i = 1; i < n; ++i) {
            lower += islower(s[i]);
            upper += isupper(s[i]);
            number += isdigit(s[i]);
            if (s[i] == cur) {
                ++repeat;
            }
            if (s[i] != cur || i == n-1){
                replace += repeat/3;
                add += (repeat-1)/2;
                remove += max(0, repeat - 2);
                if (repeat > 2) {
                    repeatVec.push_back(repeat);
                }
                repeat = 1;
                cur = s[i];
            }
        }
        
        int miss = 0;
        if (!lower)
            ++miss;
        if (!upper)
            ++miss;
        if (!number)
            ++miss;
        
        if (n < 6) {
            return max(max(6 - n, miss), add);
        }
        
        if (n <= 20) {
            return max(replace, miss);
        }
        
        int needRemove = n - 20;
        if (needRemove >= remove) {
            return needRemove + miss;
        } else {
            int R = needRemove;
            int m = repeatVec.size();
            vector<vector<int>> dp(R+1, vector<int>(m+1, INT_MAX));
            dp[0][0] = 0;
            for (int j = 1; j <= m; ++j) {
                dp[0][j] = dp[0][j-1] + repeatVec[j-1]/3;
            }
            
            for (int r = 1; r <= R; ++r) {
                for (int j = 1; j <= m; ++j) {
                    for (int s = 0; s <= min(repeatVec[j-1]-2, r); ++s) {
                        if (dp[r-s][j-1] < INT_MAX) {
                            dp[r][j] = min(dp[r][j], dp[r-s][j-1] + (repeatVec[j-1]-s)/3);
                        }
                    }
                }
            }
            
            return needRemove + max(dp[R][m], miss);
        }
    }
};