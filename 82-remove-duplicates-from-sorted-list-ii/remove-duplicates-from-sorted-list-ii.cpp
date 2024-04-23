class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummy=new ListNode(101);
        dummy->next=head;
        ListNode* x=dummy;
        while(x)
        {
            ListNode* tmp=x->next;
            int flag=0;
            while(tmp && tmp->next && tmp->val == tmp->next->val)
            {
                tmp=tmp->next;
                flag=1;
            }
            if(flag)
                x->next=tmp->next;
            else
                x=x->next;
        }
        return dummy->next;
    }
};