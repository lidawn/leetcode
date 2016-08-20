/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //之前考虑麻烦了
    //先找中间节点，中间节点是根节点，再递归左右部分
    TreeNode* build(ListNode *head,ListNode *end)
    {
        if(head==NULL || head==end)return NULL;
        //if(head==end)return new TreeNode(head->val);
        ListNode *slow,*fast;
        slow=fast=head;
        while(fast!=end&&fast->next!=end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = build(head,slow);
        root->right = build(slow->next,end);
        return root;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)return NULL;
        //不包括end
        return build(head,NULL);
    }
};