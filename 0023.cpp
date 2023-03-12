#include <vector>
#include <queue>
using namespace std;

/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //priority_queue
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) { 
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for(ListNode *l : lists) {
            if (l) q.push(l);
        }
        if(q.empty()) return NULL;

        ListNode pre(0);
        ListNode *node = &pre;
        while (q.size()) {
            ListNode *top = q.top();
            q.pop();
            node->next = top;
            node = node->next;
            if (top->next) {
                q.push(top->next);
            }
        }
        return pre.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n < 1) return nullptr;
        ListNode* res = lists[0];
        for (int i = 1; i < n; i++) {
            res = merge(res, lists[i]);
        }

        return res;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode *p = l1;
        if (l1 -> val < l2 -> val) {
            p = l1;
            l1 = l1 -> next;
        } else {
            p = l2;
            l2 = l2 -> next;
        }

        ListNode *res = p;
        while (l1 && l2) {
            if (l1 -> val < l2 -> val) {
                p -> next = l1;
                l1 = l1 -> next;
            } else {
                p -> next = l2;
                l2 = l2 -> next;
            }
            p = p -> next;
        }

        if (l1) {
            p -> next = l1;
        }

        if (l2) {
            p -> next = l2;
        }

        return res;
    }
};