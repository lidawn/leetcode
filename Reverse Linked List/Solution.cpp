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
/*
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
*/ 
    //递归
  
    void reverse(ListNode* &p)
    {
        if(!p)return;
        ListNode *rest = p->next;
        if(!rest)return;
        reverse(rest);
        p->next->next = p;
        p->next = NULL;
        p =rest;
    }
    ListNode* reverseList(ListNode* head) {
        reverse(head);
        return head;
    }
    
    
};