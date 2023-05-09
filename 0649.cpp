#include <queue>
#include <string>
using namespace std;

/*
In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".
*/

class Solution {
public:
    // Each senate R must ban its next closest senate D who is from another party, or else D will ban its next senate from R's party. 
    // The idea is to use two queues to save the index of each senate from R's and D's parties, respectively. 
    // During each round, we delete the banned senate's index; and plus the remainning senate's index with n(the length of the input string senate), 
    // then move it to the back of its respective queue.
    string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        int n = senate.length();

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') q1.push(i);
            else q2.push(i);
        }

        while (!q1.empty() && !q2.empty()) {
            int si = q1.front(), di = q2.front();
            q1.pop(), q2.pop();
            if (si < di) q1.push(si + n);
            else q2.push(di + n);
        }

        return q1.size() > q2.size() ? "Radiant" : "Dire";
    }
};