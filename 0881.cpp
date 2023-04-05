#include <vector>
#include <algorithm>
using namespace std;

/*
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.
*/

class Solution {
public:
    // Two pointers: make the lightest & heaviest person to go together.
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;
        int res = 0;
        while (l <= r) {
            if (people[l] + people[r] <= limit)
                l++;
            r--;
            res++;
        }

        return res;
    }
};