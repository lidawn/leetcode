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
    ListNode* partition(ListNode* head, int x) {
        ListNode *pre=head,*p,*tmp,*tmp2;
        bool flag=false;
        if(head==NULL || head->next==NULL)return head;
        if(head->val >= x)
        {
            pre=head;
            flag=true;
        }
        else while(pre->next!=NULL && pre->next->val < x)pre=pre->next;
        for(p=pre;p!=NULL&&p->next!=NULL;)
        {
            if(p->next->val < x)
            {
                if(flag)
                {
                    tmp = p->next->next;
                    head = p->next;
                    head->next = pre;
                    p->next = tmp;
                    pre = head;
                    flag=false;
                }
                else
                {
                tmp = p->next->next;
                tmp2 = pre->next;
                pre->next = p->next;
                p->next->next = tmp2;
                p->next = tmp;
                pre = pre->next;
                }
            }
            else p = p->next;
        }
        return head;
    }
};