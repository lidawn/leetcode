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
        TreeNode *pre=NULL;
        if(root)st.push(root);
        while(!st.empty())
        {
            tmp = st.top();
            if((tmp->left==NULL&&tmp->right==NULL)||(pre!=NULL&&(pre==tmp->left||pre==tmp->right)))
            {
                ret.push_back(tmp->val);
                st.pop();
                pre = tmp;
            }
            else
            {
                if(tmp->right)
                    st.push(tmp->right);
                if(tmp->left)
                    st.push(tmp->left);
            }
        }
        return ret;
    }
};