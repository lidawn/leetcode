/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a,b,carry=0;
        ListNode *phead =  new ListNode(0);
        ListNode *head=phead;
        while(l1!=NULL || l2!=NULL)
        {
            head->next = new ListNode(0);
            if(l1==NULL)a=0;
            else a= l1->val;
            if(l2==NULL)b=0;
            else b = l2->val;
            head->next->val = (a+b+carry)%10;
            carry = (a+b+carry)/10;
            head = head->next;
            if(l1!=NULL)l1=l1->next;
            if(l2!=NULL)l2=l2->next;
        }
        if(carry)head->next = new ListNode(carry);
        return phead->next;
        
    }
};