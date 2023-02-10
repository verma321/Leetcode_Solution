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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)
        return head;
        int len=0;
        ListNode *p=head,*ptr=head,*temp;
        while(p->next!=NULL)
        {
            len++;
            p=p->next;
        }
        k%=len+1;
        if(k==0)
        return head;
        len-=k;
        while(len--)
        {
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=NULL;
        p->next=head;
        return temp;
    }
};