#include <string>
#include <unordered_set>
using namespace std;

/*
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.
*/

class Solution {
public:
    // Set the corresponding bit of the character.
    // O(1)
    int partitionString(string s) {
        int i = 0, ans = 1, flag = 0;
        while(i < s.size()){
            int val = s[i] - 'a';
            if( flag & (1<<val) ) {
                flag = 0;
                ans++;
            }
            flag = flag | (1<<val);
            i++;
        }
        return ans;
    }

    int partitionString(string s) {
        unordered_set<char> partition;
        int res = 1;
        for (char c: s) {
            if (partition.count(c)) {
                partition.clear();
                res++;
            }
            partition.insert(c);
        }
        return res;
    }
};