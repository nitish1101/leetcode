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
    bool countNodes(ListNode* head, int k)
    {
        int c=0;
        while(head)
        {
            c++;
            head=head->next;
        }
        if(c<k)
            return false;
        return true;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return head;
        if(!countNodes(head,k))
            return head;
        int c=0;
        ListNode *prev=NULL,*curr=head;
        while(curr && c<k)
        {
            c++;
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};