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
    bool isPalindrome(ListNode* head) {
        //用快慢指针找中点
        ListNode *slow=head,*fast=head;
        if(head ==NULL||head->next == NULL)return true;
        while(fast->next!=NULL && fast->next->next !=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //就地逆置
        ListNode *insert = slow->next->next;
        if(insert==NULL)
        {
            if(slow->next->val == head->val)return true;
            else return false;
        }
        ListNode *pre = slow->next,*next = insert->next;
        
        while(insert)
        {
            insert->next = slow->next;
            slow->next = insert;
            pre->next = next;
            insert = next;
            if(insert!=NULL)next = insert->next;
        }
        slow = slow->next;
        while(slow!=NULL)
        {
            if(slow->val != head->val)return false;
            slow=slow->next;
            head = head->next;
        }
        return true;
        
    }
};