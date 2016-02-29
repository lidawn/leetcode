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
        ListNode *p=head,*tmp;
        if(p==NULL || p->next == NULL)return p;
        while(p->next)
        {
            if(p->next->val == p->val)
            {
                tmp = p->next;
                p->next = p->next->next;
                free(tmp);
            }
            else p = p->next;
        }
        return head;
    }
};