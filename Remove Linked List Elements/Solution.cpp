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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tmp = head,*pre=NULL;
        if(tmp==NULL)return NULL;
        while(tmp->next)
        {
            if(tmp->next->val == val)
            {
                pre = tmp->next;
                tmp->next = tmp->next->next;
                free(pre);
            }
            else tmp = tmp->next;
        }
        tmp = head;
        if(head->val==val)
        {
            head = head->next;
            free(tmp);
        }
        return head;
    }
};