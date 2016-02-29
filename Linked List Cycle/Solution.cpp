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
    bool hasCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;
        if(slow!=NULL && slow->next != NULL)fast = slow->next;
        else return false;
        for(;fast!=NULL && fast->next !=NULL;fast = fast->next->next,slow = slow->next)
            if(fast==slow)return true;
        return false;
    }
};