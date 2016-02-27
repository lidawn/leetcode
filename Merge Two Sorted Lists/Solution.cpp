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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head1 = l1,*head2=l2,*t1,*t2;
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val > l2->val)
        {
            head1 = l2;
            head2 = l1;
            l1 = l2;
        }
       while(head1->next && head2)
       {
           if(head1->next->val < head2->val)head1 = head1->next;
           else
           {
               t1 = head2;
               while(head2->next && head2->next->val <= head1->next->val) head2 = head2->next;
               t2 = head2->next;
               head2->next = head1->next;
               head1->next = t1;
               head1 = head2->next;
               head2 = t2;
           }
       }
       if(head2)head1->next = head2;
       return l1;
        
    }
};