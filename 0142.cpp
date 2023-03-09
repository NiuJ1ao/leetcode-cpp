#include <stdio.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). 
It is -1 if there is no cycle. Note that pos is not passed as a parameter.
*/

class Solution {
public:
    //  Floyd Cycle Detection - fast slow pointers
    ListNode *detectCycle(ListNode *head) {
        if (!head) return head;
        ListNode *fast = head, *slow = head;

        while (slow && fast && fast->next) {
            slow = slow -> next;
            fast = (fast -> next) -> next;
            if (slow == fast) {
                // find the start of loop
                // the distance between the head location and entry location == the distance between the meeting location and the entry location along the direction of forward movement.
                // Proof:
                //  X: distance between head and loop start, Y: distance between loop start and meet point
                //  C: distance of loop
                //  Slow pointer has traveled X + Y + s*C, where s is any positive constant.
                //  Fast pointer has traveled X + Y + f*C, where f is any positive constant.
                //  Since fast pointer covers twice the distance the slow pointer convered,
                //  X + Y + f*C = 2(X + Y + s*C)
                //  X + Y = f*C - 2*s*C
                //  f*C - 2*s*C = k*C, where k is some positive constant.
                //  Thus, X + Y = k*C, X = k*C - Y
                //  So the head and slow pointers will meet after traveling X distance at the loop start.
                while (head != slow) {
                    slow = slow -> next;
                    head = head -> next;
                }
                return head;
            }
        }

        return NULL;
    }
};