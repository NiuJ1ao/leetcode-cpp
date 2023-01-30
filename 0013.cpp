#include <unordered_map>
using namespace std;

/* 
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
For example, 2 is written as II in Roman numeral, just two ones added together. 
12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. The same principle applies to the number nine, 
which is written as IX.
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) \
            || (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) \
            || (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M'))) {
                res += m[s[i+1]] - m[s[i]];
                i++;
            } else {
                res += m[s[i]];
            }
        }
        return res;
    }

    int romanToInt(string s) {
        unordered_map<char, int> m{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(m[s[i]] < m[s[i+1]])
                ans -= m[s[i]];
            else
                ans += m[s[i]];
        }
        return ans;
    }
};