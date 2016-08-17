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
    ListNode* reverse(ListNode *head)
    {
         ListNode *cur=head,*tmp=NULL;
         ListNode *pre=NULL;
         while(cur)
        {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    void merge(ListNode *first,ListNode *second)
    {
        ListNode *tmp1=NULL,*tmp2=NULL;
        while(first&&second)
        {
            tmp1 = first->next;
            tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
    void reorderList(ListNode* head) {
        //先找中间节点
        if(head==NULL) return;
        ListNode *slow=head,*fast=head;
        while(!(fast->next==NULL || fast->next->next==NULL))
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<slow->val;
        //翻转后半部分
        
        ListNode *second = slow->next;
        slow->next = NULL;
        second = reverse(second);
        //cout<<"test"<<second->val;
        ListNode *first = head;
        merge(first,second);

    }
};