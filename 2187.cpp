#include <vector>
#include <algorithm>
using namespace std;

/*
You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.
*/


class Solution {
public:
    // binary search
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());

        // worst case is 1 bus that takes 1e7 to complete one trip and totaltrips is 1e7.
        long long l = time[0], r = 1e14;
        long long m, sum;
        while (l < r) {
            m = (l + r) / 2; 
            sum = 0;
            for (int t: time) {
                if (t <= m) {
                    sum += m / t;
                } else {
                    break;
                }
            }

            if (sum < totalTrips) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};