/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //升序，另外一种解法是可以更改节点的值
 //直接插入的基本思路是假设前i个节点是有序的
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode *key = head->next,*thead=head;
        ListNode *prekey = head;
        while(key!=NULL)
        {
            
            //插在头结点前面
            if(key->val<thead->val)
            {
                prekey->next = key->next;
                key->next = head;
                head = key;
                key = prekey->next;
                thead = head;
                continue;
            }
            while(key->val>=thead->next->val&&thead->next!=key)
                thead = thead->next;
            if(thead->next==key)
            {
                thead=head;
                prekey = key;
                key = key->next;
                continue;
            }
            prekey->next = key->next;
            key->next = thead->next;
            thead->next = key;
            key = prekey->next;
            thead = head;
        }
        return head;
    }
};