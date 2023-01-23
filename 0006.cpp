#include <string>
using namespace std;

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

class Solution {
public:
    string convert(string s, int numRows) {
        int lenS = s.length();
        if (lenS <= numRows || numRows == 1) {
            return s;
        }

        string res = "";
        int delta = 2 * numRows - 2;
        int p = 0;
        for (int row = 0; row < numRows; row++) {
            for (int i = row; i < lenS; i += delta) {
                if (row == 0 || row == numRows - 1 || i + delta - p >= lenS) {
                    res += s[i];
                } else {
                    res += s[i];
                    res += s[i + delta - p];
                }
            }
            p += 2;
            res += "\n";
        }
        return res;
    }
};