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
    ListNode *detectCycle(ListNode *head) {
        //从开头到cycle开始的长度为X，cycle开始到slow和fast重合的点的距离为Y，重合点到链表结尾的距离为Z
        //S为slow走的距离，F为fast走的距离
        //X+Y = S，X+Y+Z+Y = F，2S = F ；
        //可推出X=Z
        if(head==NULL || head->next==NULL) return NULL;
        ListNode *slow=head,*fast=head->next;
        bool flag=false;
        for(;fast!=NULL && fast->next!=NULL;fast=fast->next->next,slow=slow->next)
        {
            if(fast==slow)
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            slow = head;
            fast = fast->next;
            while(fast!=slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
        else return NULL;
    }
};