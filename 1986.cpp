#include <vector>
using namespace std;

/*
There are n tasks assigned to you. The task times are represented as an integer array tasks of length n, where the ith task takes tasks[i] hours to finish. A work session is when you work for at most sessionTime consecutive hours and then take a break.

You should finish the given tasks in a way that satisfies the following conditions:

If you start a task in a work session, you must complete it in the same work session.
You can start a new task immediately after finishing the previous one.
You may complete the tasks in any order.
Given tasks and sessionTime, return the minimum number of work sessions needed to finish all the tasks following the conditions above.

The tests are generated such that sessionTime is greater than or equal to the maximum element in tasks[i].
*/

class Solution {
public:
    // DFS + Pruning
    int minSessions(vector<int>& tasks, int sessionTime) {
        int res = tasks.size();
        vector<int> sessions;
        dfs(tasks, sessionTime, 0, sessions, &res);
        return res;
    }

    void dfs(vector<int>& tasks, int sessionTime, int idx, vector<int>& sessions, int* res) {
        // prune branches which are greater than current result
        if (sessions.size() >= *res) {
            return;
        }

        if (idx == tasks.size()) {
            *res = sessions.size();
            return;
        }

        // add the current task to the previous sessions
        for (int i = 0; i < sessions.size(); i++) {
            if (sessions[i] + tasks[idx] <= sessionTime) {
                sessions[i] += tasks[idx];
                dfs(tasks, sessionTime, idx+1, sessions, res);
                sessions[i] -= tasks[idx];
            }
        }

        // add the current task to a new session
        sessions.push_back(tasks[idx]);
        dfs(tasks, sessionTime, idx+1, sessions, res);
        sessions.pop_back();
    }

    // Can also be solved via Bitmask + DP; but it too difficult to understand.
};