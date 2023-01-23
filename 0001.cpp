#include <vector>
#include <unordered_map>
using namespace std;

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int arrlen = nums.size();
        for (int i = 0; i < arrlen; i++) {
            for (int j = i + 1; j < arrlen; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};

// use map to store the target-num
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> temp;
        int arrlen = nums.size();
        for (int i = 0; i < arrlen; i++) {
            int num_j = target - nums[i];
            if (temp.find(num_j) != temp.end()) {
                return {temp[num_j], i};
            }
            temp[nums[i]] = i;
        }
        return {-1, -1};
    }
};
