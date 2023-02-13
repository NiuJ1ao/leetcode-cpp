#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

/*
There is a safe protected by a password. The password is a sequence of n digits where each digit can be in the range [0, k - 1].

The safe has a peculiar way of checking the password. When you enter in a sequence, it checks the most recent n digits that were entered each time you type a digit.

Return any string of minimum length that will unlock the safe at some point of entering it.
*/

class Solution {
public:
    // DFS: De Bruijn Sequence
    // A de Bruijn sequence of order n on a size-k alphabet A is a cyclic sequence in which every possible length-n string on A occurs exactly once as a substring. 
    // It has length k^n, which is also the number of distinct substrings of length n on a size-k alphabet; de Bruijn sequences are therefore optimally short.
    string crackSafe(int n, int k) {
        // start from 0s
        string res = string(n, '0');
        unordered_set<string> visited;
        visited.insert(res);

        int total = pow(k, n);
        dfs(&res, visited, total, n, k);

        return res;
    }

    bool dfs(string* res, unordered_set<string>& visited, int total, int n, int k) {
        if (visited.size() == total) return true;

        // last n-1 digits
        // if the last n - 1 digits of node1 can be transformed to node2 by appending a digit from 0..k-1
        string prefix = res->substr(res->length() - n + 1);
        for (char i = '0'; i < '0' + k; i++) {
            string newNode = prefix + i;
            if (!visited.count(newNode)) {
                visited.insert(newNode);
                res->push_back(i);
                if (dfs(res, visited, total, n, k)) {
                    return true;
                }
                visited.erase(newNode);
                res->pop_back();
            }
        }
        return false;
    }
};