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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *phead = head,*tmp = NULL,*phead1=head,*phead2=NULL;
        if(m==n)return head;
        int i = 1;
        if(m==1)phead1=head;
        else
        {
            while(i!=m-1)
            {
                head = head->next;
                i++;
            }
            phead2 = head;
            head=head->next;
            i++;
            phead1=head;
        }
        while(i!=n)
        {
            tmp = head->next;
            head->next = tmp->next;
            tmp->next = phead1;
            phead1 = tmp;
            i++;
        }
        if(m!=1)
        {   
            phead2->next = phead1;
            return phead;
        }
        else return phead1;
    }
};