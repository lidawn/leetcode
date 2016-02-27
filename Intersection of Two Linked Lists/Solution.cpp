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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA,*pB = headB,*tailA = NULL,*tailB=NULL;
        if(pA==NULL||pB==NULL)return NULL;
        while(pA!=pB)
        {
            if(pA->next == NULL)
            {   tailA = pA;
                pA = headB;
            }
            else pA = pA->next;
            if(pB->next == NULL)
            {
                tailB = pB;
                pB = headA;
            }
            else pB = pB->next;
            if(tailA!=NULL && tailB!=NULL && tailA!=tailB)return NULL;
        }
        return pA;
    }
};