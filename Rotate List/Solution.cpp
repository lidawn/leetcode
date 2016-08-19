/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //这个题，感觉出的不好
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||k==0)return head;
        ListNode *slow,*fast;
        fast=slow=head;
        int i=0;
        while(i<k&&fast!=NULL)
        {
            fast = fast->next;
            i++;
        }
        
        if(fast==NULL&&i!=k)
        {
            k = k%i;
            i=0;
            fast = head;
            while(i<k&&fast!=NULL)
            {
                fast = fast->next;
                i++;
            }
        }
        if(i==0)return head;
        if(fast==NULL&&i==k)return head;
        
        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *tmp = slow->next;
        slow->next = NULL;
        fast->next = head;
        head = tmp;
        return head;
        
    }
};