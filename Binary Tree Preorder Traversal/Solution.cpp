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
    void preorderHelper(TreeNode *node,vector<int> &ret)
    {
        if(node)
        {
            ret.push_back(node->val);
            preorderHelper(node->left,ret);
            preorderHelper(node->right,ret);
        }
    }
    */
    vector<int> preorderTraversal(TreeNode* root) {
        /*
        //递归
        vector<int> ret;
        if(root)preorderHelper(root,ret);
        return ret;
        */
        //非递归
        vector<int> ret;
        stack<TreeNode*> st;
        if(root)st.push(root);
        TreeNode *tmp;
        while(!st.empty())
        {
            tmp = st.top();
            ret.push_back(tmp->val);
            st.pop();
            if(tmp->right)st.push(tmp->right);
            if(tmp->left)st.push(tmp->left);
        }
        return ret;
    }
};