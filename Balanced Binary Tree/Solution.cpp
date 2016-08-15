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
    //在求高度的时候就可以判断
    int hight(TreeNode* node)
    {
        if(node==NULL)return 0;
        else if(node->left==NULL && node->right==NULL) return 1;
        else
        {
            int leftHight = hight(node->left);
            int rightHight = hight(node->right);
            //如果不平衡直接返回-1
            if(leftHight!=-1&&rightHight!=-1&&abs(leftHight-rightHight)<=1)
                return (leftHight>rightHight ? leftHight+1 : rightHight+1);
            else return -1;
        }
    }
    bool isBalanced(TreeNode* root) {
        if(hight(root)!=-1)return true;
        else return false;
    }
};