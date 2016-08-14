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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //如果p<root<q,返回root
        if((p->val <=root->val && q->val >=root->val) || (q->val <=root->val && p->val >=root->val) )return root;
        //p>root q>root
        else if((p->val>root->val && q->val>root->val) || (q->val>root->val && p->val>root->val) )return lowestCommonAncestor(root->right, p, q);
        //p<root q<root
        else return lowestCommonAncestor(root->left, p, q);
         
        
    }
};