#include <vector>
#include <string>
using namespace std;

/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int l = 0, r = 0;
        int n = chars.size();
        vector<char> res;

        while (l < n) {
            if (r < n && chars[r] == chars[l]) {
                r++;
            } else {
                res.push_back(chars[l]);
                if (r - l > 1) {
                    string count = to_string(r - l);
                    for (int i = 0; i < count.length(); i++) 
                        res.push_back(count[i]);
                } 
                l = r;
            }
        }
        chars = res;
        return chars.size();
    }

    // inplace
    int compress(vector<char>& chars) {
        int i = 0, j = 0;
        int n = chars.size();
        if (n == 1) return 1;

        while (j < n) {
            int count = 1;
            while (j < n - 1 && chars[j] == chars[j + 1]) {
                count++;
                j++;
            }

            chars[i++] = chars[j++];
            if (count > 1) {
                for (char c: to_string(count)) {
                    chars[i++] = c;
                }
            }
        }
        return i;
    }
};