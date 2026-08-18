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
    int pairSum(ListNode* head) {
        vector<int> v;
        int maxi=0;
        
        ListNode* x=head;int n=0;
        while(x!=NULL) {
            n++;
            x=x->next;
        }
        int mid=n/2;
        
        while(mid>0)
        {
            v.push_back(head->val);
            head=head->next;
            mid--;
        }
        int i=n/2;
        while(head!=NULL)
        {
            v[n-i-1]+=head->val;
            head=head->next;
            maxi=max(maxi,v[n-i-1]);
            i++;
        }
        return maxi; 
    }
};


/***
reverse the right half
i=0th , j= mid
keep on summin the twins , calc the max




*/