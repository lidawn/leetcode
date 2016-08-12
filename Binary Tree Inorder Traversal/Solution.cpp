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
    /*
    void inorderHelper(TreeNode *node,vector<int> &ret)
    {
        if(node)
        {
            inorderHelper(node->left,ret);
            ret.push_back(node->val);
            inorderHelper(node->right,ret);
        }
    }
    */
    
    vector<int> inorderTraversal(TreeNode* root) {
      /*  
        //递归
        vector<int> ret;
        if(root)inorderHelper(root,ret);
        return ret;
      */    
        
        //非递归
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode *tmp;
        bool flag = false;
        if(root)
        {
            st.push(root);
            //是否入栈
            if(root->left)flag=true;
        }
        
        while(!st.empty())
        {
            //入栈
            if(flag)
            {
                tmp = st.top();
                if(tmp->left)st.push(tmp->left);
                else
                {
                    ret.push_back(tmp->val);
                    st.pop();
                    if(tmp->right)st.push(tmp->right);
                    else flag=false;
                }
            }
            //出栈
            else
            {
                tmp = st.top();
                ret.push_back(tmp->val);
                st.pop();
                if(tmp->right)
                {
                    st.push(tmp->right);
                    flag=true;
                }
            }
        }
        return ret;
        
    }
};