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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        stack<TreeNode*> st;
        if(root)st.push(root);
        TreeNode *tmp;
        vector<string>::iterator it;
        while(!st.empty())
        {
            int pushed = 0;
            tmp = st.top();
            
            if(ret.size()==0)
            {
                string s1;
                s1.append(1,tmp->val+'0');
                ret.push_back(s1);
                it = ret.begin();
            }
            else
            {
               
                cout<<ret.size()<<ret[1];
                 string s2=ret[0];
                 cout<<s2;
                s2+="->";
               
                s2.append(1,tmp->val+'0');
                *it = s2;
            }
            
            st.pop();
            if(tmp->right){st.push(tmp->right);pushed++;}
            if(tmp->left){st.push(tmp->left);pushed++;}
            //有两个节点，则复制一份字符串
            if(pushed==2)
            {
                string s3(*it);
                if(it+1 == ret.end())ret.push_back(s3);
                else ret.insert(it+1,s3);
                cout<<*it;
            }
            
            //没有子树，迭代器后移
            else if(pushed==0)it++;
        }
        return ret;
    }
};