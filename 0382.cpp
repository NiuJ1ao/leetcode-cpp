#include <cstdlib>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
*/

class Solution {
    ListNode *head = nullptr;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    // Reservoir sampling
    int getRandom() {
        int res = 0, i = 1;
        ListNode *p = this->head;
        while (p) {
            if (rand() % i == 0)
                res = p->val;
            i++;
            p = p->next;
        }
        return res;
    }
};