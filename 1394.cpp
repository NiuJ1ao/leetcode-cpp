#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.
*/

class Solution {
public:
    // Time: O(n) Space: O(n)
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int i: arr) {
            freq[i]++;
        }
        
        int res = -1;
        for (int i: arr) {
            if (freq[i] == i && i > res) {
                res = i;
            }
        }

        return res;
    }

    // sort
    // Time: O(nlgn) Space: O(lgn)
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());

        int cnt = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                cnt++;
            } else {
                if (arr[i - 1] == cnt) {
                    return cnt;
                }
                cnt = 1;
            }
        }

        return arr.back() == cnt ? cnt : -1;
    }

    // heap
    // The benefit of a heap is that it does not sort elements upfront, but as you are popping them. When you find the lucky integer, you do not need to sort the rest of the heap.
    int findLucky(vector<int>& arr) {
        make_heap(begin(arr), end(arr));
        int cnt = 1, last = -1;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr.front() == last)
                ++cnt;
            else {
                if (last == cnt)
                    return cnt;
                last = arr.front();
                cnt = 1;
            }
            pop_heap(arr.begin(), arr.end() - i);
        }
        return arr.front() == cnt ? cnt : - 1; 
    }

    // linked list - best solution
    // The idea is to use the input array to store counts. This approach, however, is quite tricky to implement correctly!
    // We can think of our array as a linked list, where arr[i] points to arr[arr[i] - 1] and so on, until the element that points to itself, 
    // or its outside of the array (and we do not care about that elements, per the intuition above).
    // After we visit arr[arr[i] - 1], we can use that element to track the count of arr[i]. 
    // For the count, we will use a negative value to distinguish between pointers and counts.
    // Time: O(n) Space: O(1)
    int findLucky(vector<int>& arr) {
        for (auto i = 0; i < arr.size(); ++i) {
            auto p = i, val = arr[i];
            while (val > 0 && val <= arr.size()) {
                auto n_val = arr[val - 1];
                arr[val - 1] = min(0, arr[val - 1]) - 1;
                if (val - 1 <= i || val - 1 == p)
                    // break when the element points to itself, or points to a node that we visited earlier.
                    break;
                p = val - 1;
                val = n_val;
            }      
        }
        for (auto i = arr.size(); i > 0; --i)
            if (-arr[i - 1] == i)
                return i;
        return -1;
    }
};