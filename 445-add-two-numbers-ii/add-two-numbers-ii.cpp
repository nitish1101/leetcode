/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next; // Save next node
            curr->next = prev;               // Reverse the link
            prev = curr;                     // Move prev forward
            curr = nextNode;                 // Move curr forward
        }

        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);

        ListNode dummy(0);
        ListNode* x = &dummy;

        int carry = 0;

        while (l1 || l2 || carry) {
            int val = carry;

            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }

            carry = val / 10;

            x->next = new ListNode(val % 10);
            x = x->next;
        }

        return reverseList(dummy.next);
        
    }
};