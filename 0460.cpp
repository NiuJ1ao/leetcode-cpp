#include <list>
#include <unordered_map>
using namespace std;

/*
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.
*/

class LFUCache {
    // key: frequency, value: linked list of original key-value pairs that have the same frequency.
    unordered_map<int, list<pair<int, int>>> frequencies;
    // key: original key, value: pair of frequency and the iterator corresponding key in the frequencies map's list.
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    int capacity;
    int minf;

    void insert(int key, int frequency, int value) {
        frequencies[frequency].push_back({key, value});
        cache[key] = {frequency, --frequencies[frequency].end()};
    }

public:
    LFUCache(int capacity) : capacity(capacity), minf(0) {}

    int get(int key) {
        const auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        const int f = it->second.first;
        const auto iter = it->second.second;
        const pair<int, int> kv = *iter;
        frequencies[f].erase(iter);
        if (frequencies[f].empty() && minf == f) {
            ++minf;
        }
        insert(key, f + 1, kv.second);
        return kv.second;
    }

    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        const auto it = cache.find(key);
        if (it != cache.end()) {
            it->second.second->second = value;
            get(key);
            return;
        }
        if (capacity == cache.size()) {
            cache.erase(frequencies[minf].front().first);
            frequencies[minf].pop_front();
        }
        minf = 1;
        insert(key, 1, value);
    }
};

class LFUCache {
    unordered_map<int, int> cache;
    unordered_map<int, int> k2c;
    unordered_map<int, list<int>> c2k;
    unordered_map<int, list<int>::iterator> k2i;
    int capacity;
    int minCount;
    
    void updateCount(int key) {
        int count = k2c[key];
        c2k[count].erase(k2i[key]);
        c2k[count+1].push_back(key);
        k2i[key] = --c2k[count+1].end();
        if (c2k[count].empty() && minCount == count) minCount++;
        k2c[key]++;
    }

public:
    LFUCache(int capacity) : capacity(capacity), minCount(0) {}

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        updateCount(key);
        return cache[key];
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        if (cache.count(key)) {
            // update value
            cache[key] = value;
            updateCount(key);
            return;
        } 
        
        if (capacity == cache.size()) {
            int lfu = c2k[minCount].front();
            c2k[minCount].pop_front();
            cache.erase(lfu);
            k2c.erase(lfu);
            k2i.erase(lfu);
        }
        minCount = 1;
        cache[key] = value;
        k2c[key] = 1;
        c2k[1].push_back(key);
        k2i[key] = --c2k[1].end();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */