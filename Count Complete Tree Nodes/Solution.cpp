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
    /*递归
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int height=1;
        while(right!=NULL)
        {
            height++;
            right = right->right;
            left = left->left;
        }
        //cout<<height;
        if(left==NULL)return (1<<height) -1;
        else return 1+ countNodes(root->left) + countNodes(root->right);
    }
    */
    
    /*非递归,没理解*/
    int countNodes(TreeNode* root) {
        int hl=0,hr=0;
        int ret = 0;
        TreeNode *left= NULL, *right=NULL;
        while(root)
        {
            //分别求左右子树的左子树高度
            left = root->left;
            right = root->right;
            if(!hl)
            {
                while(left)
                {
                    hl++;
                    left = left->left;
                }
            }
            if(!hr)
            {
                while(right)
                {
                    hr++;
                    right = right->left;
                }
            }
            
            //如果高度相同，说明最后一个NULL节点在右子树
            //否则在左子树
            if(hl==hr)
            {
                root = root->right;
                ret += 1<<hl;
                hl--;
                hr=0;
            }
            else
            {
                root = root->left;
                ret += 1<<hr;
                hl--;
                hr=0;
            }
        }
        return ret;
    }
};