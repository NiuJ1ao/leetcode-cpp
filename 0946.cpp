#include <vector>
#include <stack>
using namespace std;

/*
Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int i = 0, j = 0;

        while (i < n) {
            st.push(pushed[i]);
            while (j < n && !st.empty() && popped[j] == st.top()) {
                st.pop();
                j++;
            }
            i++;
        }

        while (j < n && !st.empty() && popped[j] == st.top()) {
            st.pop();
            j++;
        }

        return st.empty();
    }
};