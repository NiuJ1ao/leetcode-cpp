#include <string>
#include <vector>
using namespace std;

// KMP

class Solution {
public:
    int strStr(string haystack, string needle) {
        int M = needle.length(); // pattern length
        int N = haystack.length();  // text length

        // longest prefix
        // “AABAACAABAA”, lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]
        vector<int> lps(M);
        // preprocess the pattern
        int len = 0;
        int idx = 1;
        while (idx < M) {
            if (needle[idx] == needle[len]) {
                len++;
                lps[idx] = len;
                idx++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[idx] = 0;
                    idx++;
                }
            }
        }

        // kmp
        int i = 0, j = 0;
        while ((N - i) >= (M - j)) {
            if (needle[j] == haystack[i]) {
                i++;
                j++;
            }

            if (j == M) {
                return i - j;
                // j = lps[j - 1];
            } 
            // else
            if (i < N && needle[j] != haystack[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }
};