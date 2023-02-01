#include <string>
#include <stack>
#include <algorithm>
using namespace std;

/*
Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.
*/

class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> stack;
        int idx = -1;
        for (int i = 0; i < word.length(); i++) {
            stack.push(word[i]);
            if (word[i] == ch) {
                idx = i + 1;
                break;
            }
        }

        for (int i = 0; i < idx; i++) {
            word[i] = stack.top();
            stack.pop();
        }

        return word;
    }

    // use c++ api
    string reversePrefix(string word, char ch) {
        reverse(word.begin(), word.begin() + word.find(ch) + 1);
        return word;
    }
};