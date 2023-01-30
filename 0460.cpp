#include <list>
#include <unordered_map>
using namespace std;

class LFUCache {
    // key: frequency, value: list of original key-value pairs that have the same frequency.
    unordered_map<int, list<pair<int, int>>> frequencies;
    // key: original key, value: pair of frequency and the iterator corresponding key in the
    // frequencies map's list.
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