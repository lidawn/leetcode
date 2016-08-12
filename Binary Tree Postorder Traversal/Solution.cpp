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
    void postorderHelper(TreeNode *node,vector<int> &ret)
    {
        if(node)
        {
            postorderHelper(node->left,ret);
            
            postorderHelper(node->right,ret);
            ret.push_back(node->val);
        }
    }
    */
    
    
    vector<int> postorderTraversal(TreeNode* root) {
       /*
        //递归
        vector<int> ret;
        if(root)postorderHelper(root,ret);
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
            if(root->left||root->right)flag=true;
        }
        
        while(!st.empty())
        {
            //入栈
            tmp = st.top();
            if(flag)
            {
                if(tmp->right&&flag)
                {
                    st.push(tmp->right);
                    flag = true;
                }
                if(tmp->left&&flag)
                {
                    st.push(tmp->left);
                    flag = true;
                }
                if(tmp->left==NULL&&tmp->right==NULL)
                {
                    ret.push_back(tmp->val);
                    st.pop();
     
                }
            }
            else
            {
                ret.push_back(tmp->val);
                    st.pop();
                    flag = false;
            }
        }
        return ret;
    }
};