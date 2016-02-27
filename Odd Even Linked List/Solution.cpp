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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)return head;
        ListNode *even = head->next,*odd = even->next,*pre = head,*tmp = NULL;
        int i = 0;
        for(;even->next!=NULL;i++)
        {
            if(i%2)even = even->next;
            
            else
            {
                odd = even->next;
                tmp = pre->next;
                pre->next = odd;
                even->next = odd->next;
                odd->next = tmp;
                pre = odd;
            }
        }
        return head;
    }
};