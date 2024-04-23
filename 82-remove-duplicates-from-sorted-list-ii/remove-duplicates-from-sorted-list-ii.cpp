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
 /***

0  1 2 3 3 3 4 4 5
     *     #  
   1 2------>4 4 5 
     *         #
   1 2---------->5->N
     *(*)           #
                 *  #(#->NXT && #)
                 *=*->NXT 

   1 2 5
 */
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
                ListNode* del=tmp;
                tmp=tmp->next;
                delete del;
                flag=1;
            }
            if(flag){
                    x->next=tmp->next;
                    delete tmp;
            }
            else
                x=x->next;
        }
        return dummy->next;
    }
};