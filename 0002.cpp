struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* tmp = res;
        int n1, n2, carry = 0;
        while (l1 || l2 || carry != 0) {
            if (l1 == nullptr) {
                n1 = 0;
            } else {
                n1 = l1 -> val;
                l1 = l1 -> next;
            }

            if (l2 == nullptr) {
                n2 = 0;
            } else {
                n2 = l2 -> val;
                l2 = l2 -> next;
            }

            int sum = n1 + n2 + carry;
            carry = (int) sum / 10;

            ListNode* nextNode = new ListNode(sum % 10);
            tmp -> next = nextNode;
            tmp = tmp -> next;
        }
        return res -> next;
    }
};
