#include <list>
#include <unordered_map>
using namespace std;

/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
*/

class LRUCache {
    list<pair<int, int>> lruList; // front - most recently used, back - least recently used
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int capacity;

public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        // splice(): takes the element at the m[key] and places it at the beginning of the list.
        lruList.splice(lruList.begin(), lruList, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            // update value
            lruList.splice(lruList.begin(), lruList, cache[key]);
            cache[key]->second = value;
            return;
        }

        if (lruList.size() == capacity) {
            // evict
            int lruKey = lruList.back().first;
            lruList.pop_back();
            cache.erase(lruKey);
        }
        lruList.push_front({key, value});
        cache[key] = lruList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */