#include <vector>
#include <set>
#include <map>
using namespace std;

/*
Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

Implement the SummaryRanges class:

SummaryRanges() Initializes the object with an empty stream.
void addNum(int value) Adds the integer value to the stream.
int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.
*/

// naive
class SummaryRanges {
public:
    vector<int> stream;
    int streamSize;

    SummaryRanges() {
        streamSize = 0;
    }
    
    void addNum(int value) {
        for (int i = 0; i < streamSize; i++) {
            if (stream[i] == value) return;
            if (stream[i] > value) {
                stream.insert(stream.begin() + i, value);
                streamSize++;
                return;
            }
        }
        stream.push_back(value);
        streamSize++;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        int startIdx = 0;
        for (int i = 0; i < streamSize; i++) {
            int j = i + 1;
            if (j >= streamSize) {
                res.push_back(vector<int>{stream[startIdx], stream[i]});
            }
            if (j < streamSize && stream[i] + 1 != stream[j]) {
                res.push_back(vector<int>{stream[startIdx], stream[i]});
                startIdx = j;
            }
        }
        return res;
    }
};

// use ordered set
class SummaryRanges {
public:
    set<int> stream;

    SummaryRanges() {}
    
    void addNum(int value) {
        stream.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        if (stream.empty()) {
            return res;
        }

        int left = -1, right = -1;
        for (int value : stream) {
            if (left < 0) {
                left = right = value;
            } else if (value == right + 1) {
                right = value;
            } else {
                res.push_back({left, right});
                left = right = value;
            }
        }
        res.push_back({left, right});
        return res;
    }
};

// use ordered set and optimized for multiple addNums. (BUT logics are messy)
class SummaryRanges {
public:
    set<int> stream;
    set<int> newNums;
    vector<vector<int>> disjoints;

    SummaryRanges() {}
    
    void addNum(int value) {
        if (!stream.count(value)) {
            stream.insert(value);
            newNums.insert(value);
        }
    }
    
    vector<vector<int>> getIntervals() {
        int idx = 0;

        for (auto it = newNums.begin(); it != newNums.end(); it++) {
            int num = *it;
            int len = disjoints.size();

            while (idx < len && num > disjoints[idx][0]) {
                idx++;
            }
            auto disjointsIt = disjoints.begin();

            // edge case: smallest num
            if (idx == 0) {
                if (len != 0 && num == disjoints[idx][0] - 1) {
                    disjoints[idx][0] = num;
                } else {
                    disjoints.insert(disjointsIt, vector<int>{num, num});
                }
            } else 
            // edge case: largest num
            if (idx == disjoints.size()) {
                if (num == disjoints[idx-1][1] + 1) {
                    disjoints[idx-1][1] = num;
                } else {
                    disjoints.push_back(vector<int>{num, num});
                }
            } 
            // in between
            else {
                // connect two disjoint pairs
                if (num == disjoints[idx][0] - 1 && num == disjoints[idx-1][1] + 1) {
                    // merge
                    vector<int> pair{disjoints[idx-1][0], disjoints[idx][1]};
                    auto disjointsIt = disjoints.begin();
                    disjoints.erase(disjointsIt + (idx-1), disjointsIt + (idx+1));
                    disjoints.insert(disjointsIt + (idx-1), pair);
                } else 
                // append to latter pair
                if (num == disjoints[idx][0] - 1) {
                    disjoints[idx][0] = num;
                } else 
                // append to previous pair
                if (num == disjoints[idx-1][1] + 1) {
                    disjoints[idx-1][1] = num;
                } 
                // disjoint num - add itself
                else {
                    disjoints.insert(disjointsIt + idx, vector<int>{num, num});
                }
            }
        }

        newNums.clear();
        return disjoints;
    }
};

// use ordered set and optimized for multiple addNums. (BUT logics are messy :( )
class SummaryRanges {
public:
    set<int> stream;
    set<int> newNums;
    vector<vector<int>> disjoints;
    int streamSize;

    SummaryRanges() {
        streamSize = 0;
    }
    
    void addNum(int value) {
        if (!stream.count(value)) {
            stream.insert(value);
            newNums.insert(value);
            streamSize++;
        }
    }
    
    vector<vector<int>> getIntervals() {
        int idx = 0;

        for (auto it = newNums.begin(); it != newNums.end(); it++) {
            int num = *it;
            int len = disjoints.size();

            while (idx < len && num > disjoints[idx][0]) {
                idx++;
            }
            auto disjointsIt = disjoints.begin();

            // edge case: smallest num
            if (idx == 0) {
                if (len != 0 && num == disjoints[idx][0] - 1) {
                    disjoints[idx][0] = num;
                } else {
                    disjoints.insert(disjointsIt, vector<int>{num, num});
                }
            } else 
            // edge case: largest num
            if (idx == disjoints.size()) {
                if (num == disjoints[idx-1][1] + 1) {
                    disjoints[idx-1][1] = num;
                } else {
                    disjoints.push_back(vector<int>{num, num});
                }
            } 
            // in between
            else {
                // connect two disjoint pairs
                if (num == disjoints[idx][0] - 1 && num == disjoints[idx-1][1] + 1) {
                    // merge
                    vector<int> pair{disjoints[idx-1][0], disjoints[idx][1]};
                    auto disjointsIt = disjoints.begin();
                    disjoints.erase(disjointsIt + (idx-1), disjointsIt + (idx+1));
                    disjoints.insert(disjointsIt + (idx-1), pair);
                } else 
                // append to latter pair
                if (num == disjoints[idx][0] - 1) {
                    disjoints[idx][0] = num;
                } else 
                // append to previous pair
                if (num == disjoints[idx-1][1] + 1) {
                    disjoints[idx-1][1] = num;
                } 
                // disjoint num - add itself
                else {
                    disjoints.insert(disjointsIt + idx, vector<int>{num, num});
                }
            }
        }

        newNums.clear();
        return disjoints;
    }
};

// Maintain all the intervals in ordered map (not faster than my method :) )
class SummaryRanges {
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int value) {
        int left = value, right = value;
        auto small_entry = intervals.upper_bound(value);
        if (small_entry != intervals.begin()) {
            auto max_entry = small_entry;
            --max_entry;
            if (max_entry->second >= value) {
                return;
            }
            if (max_entry->second == value - 1) {
                left = max_entry->first;
            }
        }
        if (small_entry != intervals.end() && small_entry->first == value + 1) {
            right = small_entry->second;
            intervals.erase(small_entry);
        }
        intervals[left] = right;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> answer;
        for (const auto& p : intervals) {
            answer.push_back({p.first, p.second});
        }
        return answer;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */