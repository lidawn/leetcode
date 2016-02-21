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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        if( maxLeft > maxRight ) return maxLeft+1;
        else return maxRight+1;
    }
};