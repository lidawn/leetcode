/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> qu;
        TreeLinkNode *node;
        if(root)qu.push(root);
        while(!qu.empty())
        {
            int size = qu.size();
            for(int i=0;i<size;i++)
            {
                node = qu.front();
                qu.pop();
                if(node->left)qu.push(node->left);
                if(node->right)qu.push(node->right);
                if(i==size-1)
                {
                    node->next = NULL;
                }
                else
                {
                    node->next =qu.front();
                }
            }
            
        }
    }
};