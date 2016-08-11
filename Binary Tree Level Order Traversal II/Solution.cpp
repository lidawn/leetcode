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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> qu;
        TreeNode *tmp=NULL;
        
        if(root)qu.push(root);
        while(!qu.empty())
        {
            vector<int> lev;
            int size = qu.size();
            for(int i=0;i<size;i++)
            {
                tmp = qu.front();
                lev.push_back(tmp->val);
                qu.pop();
                if(tmp->left)qu.push(tmp->left);
                if(tmp->right)qu.push(tmp->right);
            }
            ret.push_back(lev);
        }
        vector<vector<int>> ret_r;
        for(int i=ret.size()-1;i>=0;i--)
        {
            ret_r.push_back(ret[i]);
        }
        return ret_r;
    }
};