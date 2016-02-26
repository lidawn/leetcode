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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode *tmp,*phead = head;
        while(head->next)
        {
            tmp = head->next;
            head->next = head->next->next;
            tmp->next = phead;
            phead = tmp;
        }
        return phead;
    }
};