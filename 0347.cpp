#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

class Solution {
public: 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> topk(k);
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> pq;

        for (int i: nums) {
            freq[i]++;
        }

        for (auto& i: freq) {
            pq.push({i.second, i.first});
        }

        for (int i = 0; i < k; i++) {
            topk[i] = pq.top().second;
            pq.pop();
        }

        return topk;
    }
};

// Quickselect: Hoare's selection algorithm
// Textbook algorithm for "find kth something"
// Like quicksort
class Solution {
    unordered_map<int, int> freq;
    vector<int> unique;

public: 
    int partition(int l, int r, int pivot) {
        int pivot_freq = freq[unique[pivot]];
        
        // move pivot to the end
        swap(unique[pivot], unique[r]);

        // move all less freq elements to the left
        int idx = l;
        for (int i = l; i <= r; i++) {
            if (freq[unique[i]] < pivot_freq) {
                swap(unique[idx], unique[i]);
                idx++;
            }
        }

        // move pivot to its final place
        swap(unique[r], unique[idx]);

        return idx;
    }

    // partial sort: from less frequent to the most frequent, till
    // (n - k)th less frequent element takes its place (n - k) in a sorted array.
    void quickselect(int l, int r, int k) {
        if (l == r) return;

        int pivot = l + rand() % (r - l + 1);
        pivot = partition(l, r, pivot);

        if (k == pivot) {
            return;
        } else if (k < pivot) {
            quickselect(l, pivot - 1, k);
        } else {
            quickselect(pivot + 1, r, k);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> topk(k);

        for (int i: nums) {
            freq[i]++;
        }
        for (auto& i: freq) {
            unique.push_back(i.first);
        }
        
        int n = unique.size();
        quickselect(0, n - 1, n - k);
        copy(unique.begin() + n - k, unique.end(), topk.begin());
        return topk;
    }
};