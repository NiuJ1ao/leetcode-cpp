#include <vector>
#include <algorithm>
using namespace std;

/*
A Collection of Sorting Algorithms

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }

    // Merge Sort (nums, 0, nums.size());
    vector<int> mergeSort(vector<int>& nums, int start, int end) {
        if (end - start <= 1) {
            return vector<int>{nums[start]};
        }

        int mid = start + (end - start) / 2;
        vector<int> firstHalf = mergeSort(nums, start, mid);
        vector<int> secondHalf = mergeSort(nums, mid, end);

        // merge
        vector<int> res(end-start);
        int i = 0, j = 0;
        while (i < firstHalf.size() && j < secondHalf.size()) {
            int num1 = firstHalf[i];
            int num2 = secondHalf[j];
            if (num1 < num2) {
                res.push_back(num1);
                i++;
            } else {
                res.push_back(num2);
                j++;
            }
        }

        while (i < firstHalf.size()) {
            res.push_back(firstHalf[i++]);
        }

        while (j < secondHalf.size()) {
            res.push_back(secondHalf[j++]);
        }

        return res;
    }

    // Counting Sort
    vector<int> countingSort(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int freqSize = maxVal - minVal + 1;
        int n = nums.size();

        vector<int> freq(freqSize, 0);
        vector<int> res(n, 0);

        for (int num: nums) 
            freq[num - minVal]++;

        for (int i = 1; i < freqSize; i++)
			freq[i] += freq[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            res[freq[nums[i] - minVal] - 1] = nums[i];
            freq[nums[i] - minVal]--;
        }

        return res;
    }

    // Heap Sort
    void heapSort(vector<int> &nums) {
        int n = nums.size();

        // heapify
        for(int i = n / 2 - 1; i >= 0; i--)
            siftDown(nums, n, i);
        
        // sorting
        for (int i = n - 1; i >= 0; i--) {
            swap(nums[0], nums[i]);
            siftDown(nums, i, 0);
        }
    }

    void siftDown(vector<int>& nums, int n, int i) {
        int maxIdx = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && nums[maxIdx] < nums[l])
            maxIdx = l;
        if (r < n && nums[maxIdx] < nums[r])
            maxIdx = r;
        if (maxIdx != i) {
            swap(nums[i], nums[maxIdx]);
            siftDown(nums, n, maxIdx);
        }
    }


    // Quick Sort (nums, 0, nums.size() - 1);
    void quickSort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int i = l;
        for (int j = l; j < r; j++) {
            if (nums[j] < nums[r]) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        quickSort(nums, l, i-1);
        quickSort(nums, i+1, r);
    }

    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};