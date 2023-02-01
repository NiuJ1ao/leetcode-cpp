#include <vector>
#include <string>
#include <limits.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> res;
        int N = num.size();
        vector<vector<int>> nums(N);
        for (int i = 0; i < N; i++) {
            if (num[i] == '0')  {
                nums[i].push_back(0);
                continue;
            }
            for (int len = 1; len <= N - i; len++) {
                int sub = stoi(num.substr(i, len));
                if (sub < INT_MAX) {
                    nums[i].push_back(sub);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int ele: nums[i]) {
                cout << ele << " ";
            }
            cout << endl;
        }

        for (int j = 0; j < nums[0].size(); j++) {
            cout << nums[0][j] << " "; 
            int first = nums[0][j];
            // if (helper(nums, )) {
            //     res.
            // }
        }

        return res;
    }

    bool helper(vector<vector<int>>& nums, vector<int>& res, int i, int j) {

    }
};