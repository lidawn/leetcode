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
    ListNode* swapPairs(ListNode* head) {
        ListNode* phead = head,*tmp = NULL;
        //0 1 个节点
        if(head==NULL || head->next == NULL)return head;
        head = head->next;
        while(head->next)
        {
            if(head->next->next)
            {
                tmp =head->next;
                head->next = head->next->next;
                tmp->next = head->next->next;
                head->next->next = tmp;
                head = tmp;
            }
            else break;
        }
        //前两个节点
        head = phead;
        tmp = head->next;
        head->next = head->next->next;
        tmp->next = phead;
        phead = tmp;
        return phead;
    }
};