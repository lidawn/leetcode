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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *phead = head,*front=head;
        int i=1;
        while(i<n)
        {
            front = front->next;
            i++;
        }
        if(front->next == NULL)
        {
            phead = head->next;
            free(head);
            return phead;
        }
        front = front->next;
        while(front->next)
        {
            head = head->next;
            front = front->next;
        }
        front = head->next;
        head->next = head->next->next;
        free(front);
        return phead;
    }
};