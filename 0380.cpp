#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.
*/

// O(1)
class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> nums;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (mp.count(val)) return false;
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!mp.count(val)) return false;
        mp[nums.back()] = mp[val];
        swap(nums[mp[val]], nums.back());
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

// O(n) getRandom()
class RandomizedSet {
    unordered_set<int> s;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (!s.count(val)) {
            s.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (s.count(val)) {
            s.erase(val);
            return true;
        }
        return false;
    }
    
    // Reservoir sampling
    int getRandom() {
        int res = 0, i = 1;
        for (int val: s) {
            if (rand() % i == 0)
                res = val;
            i++;
        }
        return res;
    }
};
