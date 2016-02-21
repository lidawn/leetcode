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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return minDepth(root->right) +1;
        if(!root->right) return minDepth(root->left) +1;
        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);
        if(minLeft<minRight) return minLeft+1;
        else return minRight+1;
    }
};