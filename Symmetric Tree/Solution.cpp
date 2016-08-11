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
    bool isSymmetric_s(TreeNode *left, TreeNode *right)
    {
        if(left==NULL&&right==NULL)return true;
        else if(left&&right&&left->val==right->val)
            return isSymmetric_s(left->right,right->left)&&isSymmetric_s(left->left,right->right);
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        /*
        queue<TreeNode*> qu;
        TreeNode *tmp;
        if(root)qu.push(root);
        else return true;
        //平均4ms  我的16ms
        while(!qu.empty())
        {
            int size = qu.size();
            //进队列
            int *vals = new int[size];
            for(int i=0;i<size;i++)
            {
                tmp = qu.front();
                if(tmp)vals[i] = tmp->val;
                else vals[i] = 0;
                qu.pop();
                if(tmp)
                {
                    qu.push(tmp->left);
                    qu.push(tmp->right);
                }
            }
            //比较队列是否对称
            int start=0,end=size-1;
            while(start<end)
            {
                cout<<vals[start];
                cout<<vals[end];
                if(vals[start]==vals[end])
                {
                    start++;
                    end--;
                }
                else return false;
            }
            delete []vals;
        }
        return true;
        */
        //递归版
        //a的左子树的左子树和a的右子树的右子树对称
        //a的左子树的右子树和a的右子树的左子树对称
        //递归的4ms
        if(root==NULL)return true;
        return isSymmetric_s(root->left,root->right);
    }
   
};