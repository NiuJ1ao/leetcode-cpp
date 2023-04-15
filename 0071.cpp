#include <string>
#include <stack>
using namespace std;

/*
Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.
*/

class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        string dir = "";
        stack<string> st;
        for (int i = 1; i < path.length(); i++) {
            if (path[i] == '/') {
                if (!dir.empty()) {
                    if (dir == ".") {
                        // fall through
                    } else if (dir == "..") {
                        if (!st.empty()) st.pop();
                    } else {
                        st.push(dir);
                    }
                    dir = "";
                }
            } else {
                dir.push_back(path[i]);
            }
        }

        string res = "/";
        if (!st.empty()) {
            res += st.top();
            st.pop();
        }
        while (!st.empty()) {
           res = "/" + st.top() + res;
           st.pop();
        }

        return res;
    }
};