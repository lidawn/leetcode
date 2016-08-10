/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //访问每一层最右边的节点，即每一次队列的最后一个元素
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> qu;
        TreeNode *tmp=NULL;
        
        if(root)qu.push(root);
        while(!qu.empty())
        {
            ret.push_back(qu.back()->val);
            int size = qu.size();
            for(int i=0;i<size;i++)
            {
                tmp = qu.front();
                qu.pop();
                if(tmp->left)qu.push(tmp->left);
                if(tmp->right)qu.push(tmp->right);
            }

        }
        return ret;
    }
};