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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow=head,*fast=head,*ptr;
        
        int m=1;
        while(m<=n)
        {
            fast=fast->next;
            m++;
        }
        if(fast==NULL)
        return slow->next;
        cout<<fast->val;
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ptr=slow->next;
        cout<<slow->val;
        slow->next=ptr->next;
        delete ptr;
        return head;
    }
};