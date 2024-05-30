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
/*
    s
          f
1-2-3-4-5
*/

class Solution {
public:
    ListNode* findMidNode(ListNode* head)
    {
        ListNode  *s=head,*f=head->next;
        while(f!=NULL && f->next!=NULL )
        {
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    ListNode* reverseLL(ListNode* head)
    {
        ListNode *prev=NULL,*curr=head,*nex;
        while(curr!=NULL)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head)
            return;
        ListNode* mid=findMidNode(head);
        ListNode* secHead=mid->next;
        mid->next=NULL;
        ListNode* revHead=reverseLL(secHead);
        
        ListNode* x=head;

        while(revHead!=NULL)
        {
            ListNode* tmp1=x->next;
            ListNode* tmp2=revHead->next;
            x->next=revHead;
            revHead->next=tmp1;
            revHead=tmp2;
            x=tmp1;

        }
    }
};