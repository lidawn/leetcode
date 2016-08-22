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
    void helper(TreeNode *root,int &i,int &k)
    {
        if(root==NULL||k<=0)return;
        helper(root->left,i,k);
        
        k--;
        if(k==0)
        {
            i=root->val;
            return;
        }
        helper(root->right,i,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=1;
        helper(root,i,k);
        return i;
    }
};