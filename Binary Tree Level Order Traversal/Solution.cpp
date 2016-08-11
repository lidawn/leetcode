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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>qu;
        vector<vector<int>> ret;
        TreeNode *tmp;
        if(root)qu.push(root);
        while(!qu.empty())
        {
            int size = qu.size();
            vector<int> sub;
            for(int i=0;i<size;i++)
            {
                tmp = qu.front();
                qu.pop();
                sub.push_back(tmp->val);
                if(tmp->left)qu.push(tmp->left);
                if(tmp->right)qu.push(tmp->right);
            }
            ret.push_back(sub);
        }
        return ret;
    }
};