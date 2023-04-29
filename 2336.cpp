#include <set>
using namespace std;

/*
You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
*/

class SmallestInfiniteSet {
    int cur;
    set<int> s;
public:
    SmallestInfiniteSet() {
        cur = 1;
    }
    
    int popSmallest() {
        if (s.size()) {
            int res=*s.begin(); 
            s.erase(res);
            return res;
        } else {
            return cur++;
        }
    }
    
    void addBack(int num) {
        if (cur>num) s.insert(num);
    }
};