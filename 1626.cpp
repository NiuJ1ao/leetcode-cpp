#include <vector>
#include <algorithm>
using namespace std;

/*
You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.
*/

class Solution {
public:
    // DP Bottom-Up - very similar to [309] Longest Increasing Subsequence.
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int res = 0;
        int len = scores.size();
        vector<int> dp(len);

        vector<pair<int, int>> ageScorePair;
        for (int i = 0; i < scores.size(); i++) {
            ageScorePair.push_back({ages[i], scores[i]});
        }
        
        // Sort in ascending order of age and then by score.
        sort(ageScorePair.begin(), ageScorePair.end());

        for (int i = 0; i < len; i++) {
            dp[i] = ageScorePair[i].second;
            res = max(res, dp[i]);
        }

        for (int i = 0; i < len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (ageScorePair[j].second <= ageScorePair[i].second) {
                    dp[i] = max(dp[i], dp[j] + ageScorePair[i].second);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};