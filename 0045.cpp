#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n

Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
*/

class Solution {
public:
    // BFS
    int jump(vector<int>& nums) {
        int n = nums.size();
        queue<int> q;
        unordered_map<int, int> steps;

        int idx = 0;
        steps[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            if (idx == n - 1) {
                return steps[idx];
            }

            for (int j = 0; j <= nums[idx]; j++) {
                int next = idx + j;
                if (!steps.count(next)) {
                    steps[next] = steps[idx] + 1;
                    q.push(idx + j);
                }
            }
        }

        return 0;
    }

    // Greedy BFS
    // maxReachable: the furthest index can be reached from current level (end of next layer)
    int jump(vector<int>& nums) {
        int n = nums.size(), i = 0, maxReachable = 0, lastJumpedPos = 0, jumps = 0;
        while(lastJumpedPos < n - 1) {  // loop till last jump hasn't taken us till the end
            maxReachable = max(maxReachable, i + nums[i]);  // furthest index reachable on the next level from current level
            if(i == lastJumpedPos) {			  // current level has been iterated & maxReachable position on next level has been finalised
                lastJumpedPos = maxReachable;     // so just move to that maxReachable position
                jumps++;                          // and increment the level
        // NOTE: jump^ only gets updated after we iterate all possible jumps from previous level
        //       This ensures jumps will only store minimum jump required to reach lastJumpedPos
            }            
            i++;
        }
        return jumps;
    }
};