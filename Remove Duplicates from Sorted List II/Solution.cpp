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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode *phead = new ListNode(0);
        phead->next = head;
        ListNode *p = phead,*q;
        while(p->next!=NULL&&p->next->next!=NULL)
        {
            if(p->next->next->val == p->next->val)
            {
                q = p->next;
                while(q->next!=NULL&&q->val==q->next->val  )q=q->next;
                p->next = q->next;
                q->next = NULL;
            }
            else p = p->next;
        }
        return phead->next;
    }
};